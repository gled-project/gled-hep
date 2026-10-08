# Gled HEP libsets

Libsets for [Gled](https://github.com/gled-project/gled) that were written
for high-energy physics: event display, grid monitoring and XRootD
monitoring. They build in a Gled build area, next to the libsets of the
main repository.

| libset | what | needs |
|---|---|---|
| `Alice/` | event display for ALICE: geometry, MC and reconstructed tracks, V0s, kinks and hits from the VSD tree | Geom1, RootGeo; ROOT Geom, EG, TreePlayer and Eve |
| `AliEnViz/` | visualization of the ALICE grid, AliEn: sites, jobs and distributed analysis, fed from MonALISA | Geom1, Var1 |
| `XrdMon/` | collector of the monitoring streams of XRootD servers: users, open files and their I/O, written to ROOT trees or reported on file close | Net1 |

Each libset has its macros in `demos/`. `XrdMon/etc/` holds the init script,
cron check and logrotate file that ran the XrdMon collectors at UCSD.
`XrdMon/docs/` holds the XrdMon documentation from the gled.org wiki
(2012-2014): an overview of XRootD monitoring and of the libset,
installation, the summary-monitoring collector, and notes on Net1.

## Building

Clone this repository next to `gled`, and add it to the libset path when
configuring Gled:

```sh
git clone https://github.com/gled-project/gled.git
git clone https://github.com/gled-project/gled-hep.git
cd gled/gled-build
export ROOTSYS=<ROOT installation> GLEDSYS=$PWD
./configure --external <prefix of the externals> \
            --libsetpath ../libsets:../../gled-hep --libsets '<auto>'
source build_env.sh
make -j8
```

The libsets' demos are then linked as `gled-build/demos/<LibSet>`. See the
README of the gled repository for running Gled.

## License

The libsets are free software under the GNU Lesser General Public License,
version 3 or later. See `LICENSE`, which also lists the third-party code in
the repository and its terms, and `AUTHORS`.
