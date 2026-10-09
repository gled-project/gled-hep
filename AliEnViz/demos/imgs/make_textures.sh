#!/bin/bash
# Generates the tileable textures of the AliEnViz demo spheres (fire, marble,
# chrome, ice) with ImageMagick 7; fixed seeds make them reproducible.

set -e
cd "$(dirname "$0")"
T=$(mktemp -d)
trap 'rm -rf $T' EXIT

# noise <size> <seed> <out>: tileable noise of four octaves, levelled to 0..1.
noise() {
  local s=$1 seed=$2 out=$3 i=0
  for r in 2 6 16 40; do
    magick -size ${s}x${s} xc: -seed $((seed + i)) +noise Random \
      -virtual-pixel tile -blur 0x$r -channel G -separate +channel \
      -auto-level $T/oct$i.png
    i=$((i + 1))
  done
  magick $T/oct0.png $T/oct1.png $T/oct2.png $T/oct3.png \
    -poly "0.04,1 0.12,1 0.3,1 0.54,1" -auto-level $out
}

# ramp <out> <color> ...: a 256-entry colour lookup table through the colours.
ramp() {
  local out=$1; shift
  local n=$(( $# - 1 )) parts=() c prev=""
  for c in "$@"; do
    [ -n "$prev" ] && parts+=( -size 1x$(( 256 / n )) "gradient:$prev-$c" )
    prev=$c
  done
  magick "${parts[@]}" -append -rotate -90 -resize 256x1! $out
}

# Fire: swirls from two noise fields, one warping the other.
noise 512 101 $T/n1.png
noise 512 202 $T/n2.png
magick $T/n1.png $T/n2.png \
  -fx "u * (1 - 0.85 * (1 - abs(sin(2*pi*(1.5*u + 1.2*v))))^6)" -auto-level $T/f.png
ramp $T/fire.png black '#3a0600' '#a02000' '#ff7a00' '#ffd060'
magick $T/f.png $T/fire.png -clut -quality 92 fire.jpg

# Marble: veins periodic in x, displaced by noise.
noise 512 303 $T/n3.png
magick $T/n3.png -fx "abs(sin(2*pi*(2*i/w + 1.2*u)))^0.18" $T/m.png
ramp $T/marble.png '#5a3a1c' '#b89870' '#e8d8c0' '#f4ecdf'
magick $T/m.png $T/marble.png -clut -quality 92 marble.jpg

# Chrome: shaded noise, tinted towards yellow in the low parts.
noise 256 404 $T/n4.png
magick $T/n4.png -virtual-pixel tile -shade 120x30 -auto-level $T/c.png
ramp $T/chrome.png '#3a3a20' '#a8a040' '#d0d0c8' white
magick $T/c.png -sigmoidal-contrast 6x50% $T/chrome.png -clut -quality 92 chrome.jpg

# Ice: noise through a blue ramp, with darker spots.
noise 256 505 $T/n5.png
ramp $T/ice.png '#001830' '#0a5a8a' '#40b0d8' '#c0f0ff'
magick $T/n5.png -sigmoidal-contrast 4x50% $T/ice.png -clut -quality 92 ice.jpg
