# STATUS

From the gled.org wiki (Foswiki), converted to markdown in 2026. Last edited in March 2012. Net1 is a libset of the gled repository; its notes are about forwarding XRootD monitoring packets.

# Net1 libset

Implements some networking services and helper classes.

- UDP packet listener, TCP forwarder (server) and TCP recipient (client).

## Notes for further development

Existing functionallity allows for collection, forwarding and broadcasting
of XRootD monitoring packets. Two extensions that would be somewhat easy to
implement:

1.  Across USA we sometimes observe some UDP packet loss (typically from a
    given sites in bursts of a couple minutes to about half a day). The idea
    is to run UDP listener to TCP server converter on sites that exhibit
    such packet loss and have the central processor collect data via TCP
    thus reducing packet loss and non-time-ordered UDP packet delivery.
    Existing `SUdpPacket` consumers can directly subscribe to several
    sources so the main trouble here is with deployment to sites (new
    service to run, change in configuration of `xrootd` servers to send
    monitoring information to local listener). 2. Once the above is done, it
    shouldn't be too hard to send concentrated UDP packets in bursts (say,
    every couple of seconds) and to additionally compress the aggregate.

-- Main.MatevzTadel - 14 Mar 2012
