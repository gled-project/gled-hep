# STATUS

From the gled.org wiki (Foswiki), converted to markdown in 2026. Last edited in September 2012. The xrd-rep-snatcher code was in the `var` svn repository, which is retired and kept as a dump.

# The summary monitoring info collector with output to ApMon / MonALISA

To get the code: `svn co https://svn.gled.org/var/trunk/xrd-rep-snatcher`

The code requires a relatively recent `Getopt::Long` (more recent than in
SLC5) and `Getopt::FileConfig` (which is not installable via rpm). Using
CPAN to get them is the best option. If you are superuser on the machine,
just install them (they go into `site_perl/` so they don't damage rpm
installed packages), otherwise just put them in some directory and add
`use lib your-dir;` somewhere at the top.

To run for debugging with output to stdout run:
`./xrd-rep-snatcher.pl --no-daemon --apmonport=0 --logfile=-`

To print out raw messages uncomment line 527: `# print LOG $raw_data, "\n";`

To print out messages after XML parsing uncomment line 528:
`# print LOG Data::Dumper::Dumper($d);`

## Example XRootD configuration stanza

    xrd.report xrdcollector.example.org:9931,another.host.org:9931 every 60s all sync

This will send reports for both `xrootd` and `cmsd` daemons. If you only
want reports from `xrootd`, put `if exec xrootd / fi` around that line.

-- Main.MatevzTadel - 15 Jul 2012
