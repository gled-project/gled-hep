# STATUS

From the gled.org wiki (Foswiki), converted to markdown in 2026. Last edited in January 2014. Describes the svn-era setup.

# XrdMon - Libset for processing of detailed monitoring data of XRootD

This document gives an overview of detailed monitoring in XRootD and
implementation of its processing in the XrdMon libset.

Related pages of interest:

- [XrdMonInstallation](XrdMonInstallation.md) - installation instructions for complete XrdMon package
- [XrdMonSummaryMonitoring](XrdMonSummaryMonitoring.md) - description of summary monitoring collection
  machinery used by AAA / USCMS

## Overview of XRootD monitoring

XRootD detailed monitoring provides a detailed, medium-latency view into
operations of XRootD servers and redirectors. Here's a list of things that
get reported:

- user authenticaton/login records (session creation);
- opening of files by a user/session;
- individual read/write requests on given <session::file> (optional);
- unpacked read/write requests for vector reads (even more optional);
- closing of files;
- termination of user sessions;
- redirection events on manager and meta-manager nodes;
- periodical "server still alive" packets.

Medium-latency means that most of the packets are buffered on the server
side and that they get sent over the network on regular intervals or once
the buffer becomes full. Typically, the interval is from 30 seconds to 5
minutes and buffer size between 1kB and 8kB.

XRootD sends monitoring information as UDP packets. `xrootd` server
configuration directive that enables the detailed monitoring is
`xrootd.monitor`, documented in [section
5.4](http://xrootd.slac.stanford.edu/doc/prod/xrd_config.htm#_Toc305602913)
of [XRootd Configuration
Reference](http://xrootd.slac.stanford.edu/doc/prod/xrd_config.htm)
document.

XRootD daemons (`xrootd` and `cmsd`) can also be configured to send summay
monitoring packets that describe operation and status of a given daemon
(number of connected clients, in/out traffic, number of working threads,
user/system time usage, etc), see documentation on `xrd.report` directive in
XRootD documentation. We have a solution for this, too, consisting of a Perl
based UDP packet receiver feeding MonALISA service and repository.

Details of both monitoring streams are described in [XRootD System
Monitoring](http://xrootd.slac.stanford.edu/doc/prod/xrd_monitoring.htm)
document.

## Overview of XrdMon implementation in Gled

Functionality required for processing of XRootD packets, building of
in-memory representation of active servers, users and opened files,
reporting usage information for each closed file, and reporting of currently
opened files via a html table is all implemented in a dedicated libset
(dynamically loadable Gled module consisting of core, GUI, and OpenGL
rendering libraries) called XrdMon. All packet processing is done by class
`XrdMonSucker` that uses classes like `XrdServer` and `XrdUser` to represent
corresponding XRootD-world entities.

`XrdMonSucker` does not listen for UDP packets directly. Instead, it
subscribes its queue to an external object that is the actual source of UDP
packets. These allows for detailed control over UDP packet processing. To
this end, several classes were also implemented in the [Net1](Net1.md) libset.
They can be divided into UDP packet sources and consumers. Here are the most
important classes:

- `UdpPacketListener` (source) - listens for UDP traffic and passes UDP
  packets (represented by a Gled class `SUdpPacket`) to registered consumer
  objects in the same Gled instance.
- `UdpPacketTcpServer` (consumer) - accepts TCP connections and forwards the
  UDP packets as `SUdpPacket` objects (including receive time, remote host
  and port information). With this, a receiver of UDP packets can serve them
  to further consumers on remote machines.
- `UdpPacketTcpClient` (source) - connects to `UdpPacketTcpServer`, receives
  the packets via TCP link and provides them for local consumers.
- `UdpPacketTreeWriter` (consumer) - writes the UDP packet into Root trees
  (compression factor ~4) for later analysis or playback (visualization,
  debuginng).

Somewhat obviously, `XrdMonSucker` is a `SUdpPacket` consumer.
`XrdMonSucker` only processes the monitoring information and maintains
in-memory representation of all ongoing user sessions and file transfers.
The following classes use this information to report activity in various
forms:

- `XrdFileCloseReporter` - base-class for implementation of classes that get
  called when a file is closed.
- `XrdFileCloseReporterGratia` - sends file-access report as a simple text
  to a given UDP destiantion.
- `XrdFileCloseReporterAmq` - sends file-access report in JSON format to
  ActiveMQ server.
- `XrdFileCloseReporterTree` - writes file-access report as an entry into a
  ROOT TTree for later analysis.
- `XrdEhs` - a simple embedded HTTP server. It serves a table of currently
  open files.

All Gled libsets depend on GledCore libset so a full list of needed libsets
for running XrdMon applications is: { GledCore, [Net1](Net1.md), XrdMon }.

## Examples of `xrootd` monitoring configurations

As mentioned above, detailed monitoring configuration is given by the
`xrootd.monitor` directive in `xrootd` config file. Please read the
corresponding XRootD monitoring documentation.

All examples request sending of server-still-alive identification messages
every five minutes (`ident 5m`). This was added in `xrootd-3.2`.

All examples request inclusion of authentication details in the new session
record (`auth`). Server takes these details from `XrdSecEntity` structure
which must be properly filled up by the authentication plugin - see
[Authentication & Access Control Configuration
Reference](http://xrootd.slac.stanford.edu/doc/prod/sec_config.htm).

### Monitoring of file open and close events

With this setup servers report session creations / user logins and file open
and file close events. Size of the file is reported as part of the file open
message. File close message includes number of bytes read from / written to
the file during the session (if number of bytes, either read or written,
exceeds 32-bits, the whole number is shifted left to fit into 32-bits + 8
bit shift amount - this leads to small loss of precision in these cases).
There is no information about individual read and write requests and no
information about data transfers, other than knowing the file is open, is
available until the file is closed.

       xrootd.monitor all auth flush 2m ident 5m mbuff 4096 window 30s dest files info user xrdcollector.example.org:9930

The packets with file open close events will be sent at least every 2
minutes (`flush 2m`) unless the buffer of 4096 bytes (`mbuff 4096`) is
filled first. There is no timing information sent with each open/close
event - instead a /time window/ structure is inserted periodically, in this
case every 30 seconds (`window 30s`). Size of each structure
(open/close/time-window) is 16 bytes. If near real-time reporting is not
reuqired, these numbers should be incresed by at least a factor of two
(`flush` and `mbuff`).

### Monitoring individual read requests

Reporting of individual read requests in the detailed monitoring stream is
requested by adding `io` to `dest` sub-directive of configuration. The read
traces include file-offset and amount of data read (or written). For vector
read requests (client requests several data-blocks with one request) number
of bytes served in each request and number of sub-blocks requested is
reported. Offsets are not reported (they are if one uses `iov` instead of
`io` but this not yet supported by XrdMon - let us know if you need this
feature).

       xrootd.monitor all auth flush io 2m ident 5m mbuff 4096 window 30s dest files io info user xrdcollector.example.org:9930

When `io` option is used `xrootd` holds data for each client session in a
separate monitoring buffer. If you want these individual buffers to be
flushed periodically, `io` should also be added to the `flush` sub-directive
(as in the example above).

**Important note:** The `io` option can greatly increase both the load on
the servers and the amount of monitoring traffic. Use this when you want to
understand the data access patterns of your applications or when you
understand them well enough to know that this will not wreck havoc, i.e.,
you know the applications are reading files in few large chunks (potentially
using vector reads).

### Monitoring of redirection activity

To monitor redirection activity add `redir` to `dest` sub-directive. Number
and size of redirection buffers can be given by parameters `rbuff` and
`rnums`.

       xrootd.monitor all auth flush io 2m ident 5m mbuff 4096 rbuff 8192 rnums 4 window 30s \
          dest files io info user redir xrdcollector.example.org:9930

XrdMon can store redirection information into a dedicated log file. More
advanced reporting is planned.

## Startup scripts for XrdMon collector configuration

As described in the implementation overview section, XrdMon can read
monitoring packets from different sources. This is configured by the first
macro specified on the command-line. After that optional macros that add
capabilities such as reporting of closed files or serving web-page of
currently opened files can be executed.

### Macros for basic application setup

These macros perform a full setup of Gled and declare some global CINT
variables.

#### `xrd_suck_udp.C`

Listen for UDP traffic and process packets with `XrdMonSucker`.

- `UdpPacketListener`: listen for UDP packets and queue them up to
  consumers.
  - Port on which to listen for UDP pakets: `c_listener->SetSuckPort(9930);`
- `XrdMonSucker`: digest XRootD monitoring information

#### `xrd_suck_tpc.C`

Run TCP client for receiving of UDP packets and process them with
`XrdMonSucker`.

- `UdpPacketTcpClient`: connect to TCP server and receive UDP packets.
  - Hostname of TCP server: `c_upc->SetHost("desire.physics.ucsd.edu");`
  - Port of TCP server (default OK if you don't change it for TCP server):
    `c_upc->SetPort(9940)`
- `XrdMonSucker`: digest XRootD monitoring information

#### Configuring XrdMon logging

A special `ZLog` object is instantiated in both macros for logging related
to XRootD activity. One can set location of the log file and set the logging
level:

- Set location of log file:
  `c_log->SetFileName("/var/log/xrootd/xrd-udp-forwarder.log");`
- Change logging level: `c_log->SetLevel(ZLog::L_Info);` (normal level),
  `c_log->SetLevel(ZLog::L_Info);` verbose.

Log rotation can be done via `logrotate` and example configurations is in
`demos/XrdMon/logrotate.d/`.

### Additional / helper macros that can be run with application macros

#### `xrd_file_close_reporter.C`

When a file-close event is registered a a file access report is sent as a
text-like UDP packet to specified address. This packet can be consumed by an
independent script, e.g., we use a Gratia probe written in python to
register the record in OSG Gratia DB. These are the available configuration
parameters:

- Set host and port to which UDP file-access report should be sent:

  ```
  c_frep_gratia->SetUdpHost("localhost");
  c_frep_gratia->SetUdpPort(4242);
  ```

Several instances of the file-close-reporter can run in parallel.

#### `xrd_file_close_reporter_amq.C`

When a file-close event is registered a a file access report is sent in JSON
format to a specified ActiveMQ server. The following parameters can be
configured:

- Set addresshost and port where ActiveMQ server is running:

  ```
  c_frep_amq->SetAmqHost("gridmsg007.cern.ch");
  c_frep_amq->SetAmqPort(6163);
  ```

- Set username and password to be used:

  ```
  c_frep_amq->SetAmqUser("xrdpop");
  c_frep_amq->SetAmqPswd("xyzz");
  ```

- Set topic where the message is to be
  sent: `c_frep_amq->SetAmqTopic("xrdpop.uscms_test_popularity");`
- Number of messages to keep in memory while connection to AMQ is down.
  After that older messages get
  dropped. `c_frep_amq->SetAmqMaxMsgQueueLen(10000);`
- Wait time after connection failure. On each new attempt the wait time will
  be doubled. `c_frep_amq->SetAmqReconnectWaitSec(1);`
- Maximum time to wait between two connection
  attempts. `c_frep_amq->SetAmqReconnectWaitSecMax(300);`

#### `xrd_http_serve_open_files.C`

Runs an embedded http server serving a html table with currently opened
files (including how much data was already read/written and when the last
monitoring packet was received). Port number is the only configurable
parameter.

By default, this is served on port 4242, e.g.: `http://foo.bar:4242/`.
Arguments understood by the http server: 1. Do not show files with same
server/client sites: `no_same_site` or `no_same_site=1`

Full URL: `http://foo.bar:4242/?no_same_site`

1.  Regexps for client domain, server domain, user DN and file-name:

  ```
  server_re=<regexp>   # e.g.: server_re=\.unl\.edu$
  client_re=<regexp>
  user_re=<regexp>
  file_re=<regexp>       # e.g.: file_re=/AOD/
  ```

Full example: `http://foo.bar:4242/?no_same_site=1&file_re=^/store/mc/` 1.
Request full client and server host names: `fqhn` or `fqhn=1` 1. Length of
displayed file-name (0 means full length, default is 64):

`file_len=40` 1. Automatic refresh period in seconds (minimum 5 seconds,
default is a server configuration variable (180s)):

`refresh=300`

Notes:

- Standard URL argument conventions apply, `/?arg1=v1&arg2=v2`
- These are perl regexps, quote appropriately.
- Apparently, some URL characters are supposed to be sent over in `%HH`
  notation; so far I only saw a blank sent as `%20` (from my firefoxen) and
  so these get replaced back to blanks.
- For debugging, the parsed arguments get listed at the bottom of the page.
- Sigh, someone should add html forms for controlling these (and refresh
  rate) without editing the URL. Help!

#### `xrd_far_tree_writer.C`

Writes file-access reports (FARs) into ROOT TTrees for later detailed
analysis. Minimal class definitions suitable for loading into a plain ROOT
session are available in the XrdMon demos directory
([sxrd-classes.h](../demos/sxrd-classes.h),
[SXrdClasses_LinkDef.h](../demos/SXrdClasses_LinkDef.h)).

This can be run as an add-on macro to application macros running
`XrdMonSucker`.

#### `xrd_udp_tree_writer.C`

Writes UDP packets into a TTree.

This can be run as an add-on macro to all application macros (as they all
have a `SUdpPacket` source).

## Startup script for UDP packet forwarding over TCP

The startup macro is `xrd_udp_forwarder.C`. It instantiates to objects:

- `UdpPacketListener`: listens for UDP packets and queues them up into
  internal queues of registered consumers.
  - Port on which to listen for UDP pakets: `c_listener->SetSuckPort(9930);`
- `UdpPacketTcpServer`: accepts TCP connections and forwards UDP packets
  over TCP to connected clients.
  - Port on which to listen for incoming TCP connections:
    `c_server->SetServerPort(9940);`

Techically, this can forward any kind of UDP traffic and only requires Net1
libset. Additional header containing receive time and source address is
attached to each UDP packet. It would be rather straightforward to implement
package coalescence and compression.

`xrd_udp_tree_writer.C` addon can also be run with this macro.

## Running in production mode - status and recommendations

Here are the recommendations for operation of XrdMon:

- Put startup / configuration macros in `/etc/gled/`.
- Put logs in `/var/log/gled/`.
- Redirect stdout, stderr and internal `saturn` log to a file in the same
  location. These logs also contain stack traces in case of trouble.
- Use `logrotate` for log rotation.

We are currently working on the following:

- reasonable `init.d` scripts and sysconfigs that could somehow be able to
  run a multitude of `gled` instances (what `xrootd` uses now seems very
  clean and reasonable);
- RPM based install (which would be much easier if all of the above gets
  solved);

Until we get this done right, you can take `demos/XrdMon/install-xrdmon.sh`
for inspiration. It does the following:

1.  copies logrotate config for `/var/log/gled/xrdmon-*.log` to
    =/etc/logrotate.d=;
2.  creates =/var/log/gled/=;
3.  copies a simple shell-script wrapper for running the demos
    (`xrdmon-wrapper.sh`) and all the CINT script into install location
    (`/opt/gled`).

With this, you can `cd /opt/gled`, edit the `.C` scripts there and start
`gled` or `saturn` with arbitrary arguments.

`xrdmon-wrapper.sh` is more of a skeleton, you still have to pass in all the
arguments (`saturn --help` and `gled --help` list the options) and the `.C`
scripts that you want to have executed. During the early deployment stages I
used run this in a `screen` session with infinite loop inside (see comments
in the file).

The following `saturn` arguments are particularly relevant:

      --noprompt          no ROOT prompt (runs TApplication insted of TRint)
      --daemon            run as daemon; implies --noprompt, std streams get closed

    Logging options:
      --log    <file>     specify log file name (saturn:'<stdout>', gled:'<null>')
                          shorthands: '-' => <null>, '+' => <stdout>
      --out    <file>     specify file name for stdout redirection
      --err    <file>     specify file name for stderr redirection
      --outerr <file>     specify file name for stdout and stderr redirection
                          shorthands: '-' => <null>, '=' => same as log
      --debug  <lvl>      set debug level (some messages require debug build)

Note that log-file given on command-line with `--log` (defaulting to
`stdout` for `saturn` and to on-screen window for `gled`) is **not** the
same as XrdMon logging configured via `ZLog` class in the CINT macro files.
Some work is required to make it possible to have all the messages going to
the same file.

-- Main.MatevzTadel - 14 Mar 2012
