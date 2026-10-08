# STATUS

From the gled.org wiki (Foswiki), converted to markdown in 2026. Last edited in October 2013. The RPMs and tarballs for EL5, EL6 and EL7 are still on ftp.gled.org; the svn repository it refers to is retired, and the sources are in the GitHub repositories.

# Building and installation of XrdMon libset (including Gled and required external software)

## Installing from RPM

RPMs are available from <https://ftp.gled.org/xrdmon/>. Yum repository is
provided at CERN, <http://linuxsoft.cern.ch/wlcg/>.

## Installing from a tarball

The EL5 and EL6 tarballs are available at <https://ftp.gled.org/xrdmon/> and
should be installed into `/opt`:

      cd /opt
      wget https://ftp.gled.org/xrdmon/gled-xrdmon-el5-current.tar.gz
      tar xzf gled-xrdmon-el5-current.tar.gz

### Running the demos

To run the demos/applications provided with Gled one needs to do:

      cd /opt/gled
      . gled-env.sh
      cd gled/demos/XrdMon/

and then modify the desired macro and run, e.g.:

      saturn xrd_suck_udp.C # no GUI
      gled   xrd_suck_udp.C # yes GUI

See section about [startup scripts and
configuration](XrdMon.md#startup-scripts-for-xrdmon-collector-configuration).

## Installing from SVN

Building of Gled is described in detail in [Gled for the
Impatient](https://github.com/gled-project/gled/blob/main/docs/gledimp.md). See also a
compilation of [build notes](https://github.com/gled-project/gled-attic/blob/main/docs/GledBuild.md) for some GNU/Linux distributions and
OSX versions. For RHEL-5 and 6 the following packages are needed for build:

      yum install gcc gcc-c++ gcc-gfortran subversion cmake autoconf automake libtool \
        libXpm-devel libXft-devel glew glew-devel gsl gsl-devel pcre-devel openssl-devel \
        libpng-devel libtiff-devel libjpeg-devel

Here, we will simply present recipes for three different builds.

### Using a script provided with XrdMon

The following commands will build tarball and RPM for Gled tag 1.4.0. The
architecture tag should be eiter `el5` or `el6`. This is used for some minor
configuration options for ROOT and for labelling of created tarballs and
RPMs.

      svn export https://svn.gled.org/gled/trunk/demos/XrdMon/rpm/build-tag.sh
      ./build-tag.sh 1.4.0 el6
      # To also publish the tarball and RPM to gled.org:
      ./build-tag.sh --publish 1.4.0 el6

### Using `gled-builder`, doing full build & install of externals and Gled

`gled-builder` is a set of scripts and makefiles used to build Gled libsets
and external software. *An aside:* Gled depends on some exotic software
(DevIL), on non-main-stream software that needs to be compiled with
multi-threading support for Gled (Fltk (also, newer Fltk versions are not
available on most systems)), and on Root which one needs to be somewhat
careful about to make sure to have a compatible version.

      dir=`pwd`
      ncpu=`cat /proc/cpuinfo  | grep -cP '^processor'`
      svn co https://svn.gled.org/gled/trunk/gled-builder
      cd gled-builder/
      autoconf
      ./configure --help
      ./configure MAKE_J_OPT="-j${ncpu}" LIBSETS="GledCore Net1 XrdMon" --prefix=${dir}/gled
      make

      # To make tarball:
      cd ${dir}/gled
      gled/demos/XrdMon/xrdmon-cleanup-for-rpm.sh
      cd ${dir}
      tarfile=gled-xrdmon-slc5-`date +%Y%m%d`.tar.gz
      tar czf ${tarfile} gled/

      # To copy it to gled.org (for Matev¸ only):
      scp ${tarfile} gled.org:/u/ftp/xrdmon/
      # To make the symlink
      ssh gled.org << FNORD
      cd /u/ftp/xrdmon/
      rm -f gled-xrdmon-slc5-current.tar.gz
      ln -s ${tarfile} gled-xrdmon-slc5-current.tar.gz
      FNORD

      # To make RPM and copy it to gled.org
      svn export http://svnweb.cern.ch/guest/dashboard/trunk/arda.dashboard.xrootd_ucsd/
      cd arda.dashboard.xrootd_ucsd
      ln -s ../${tarfile} .
      ./make-rpm.sh
      rpmdir=build/RPMS/x86_64
      rpm=`ls ${rpmdir}`
      scp ${rpmdir}/${rpm} gled.org:/u/ftp/xrdmon/

To build ROOT and Gled in debug mode, add `ROOT_GLED_DEBUG=1` to
`configure`. To build other externals in debug, add
`CFLAGS="-g" CXXFLAGS="-g"`. Unfortunatelly, configure doesn't actually
check if all the required software is available (please help). If Root
builds on the machine, you should be fine. SLC5 machines might miss some X11
development packets (`libX11-devel libXpm-devel`), `cmake`, and
`subversion`.

This will build **and** install all the stuff into directory given as
`--prefix`. If you used `/opt/gled` you should be in exactly the same
position as if you installed from a tarball. See the [instructions for
running of XrdMon demos](#running-the-demos).

### Using `gled-builder`, doing full build & install of externals and in-place/development build of Gled

Checkout and configure as for full install.

      make external  # build externals and install them under prefix
      cd gled
      make build       # checkout, configure and build gled

After this step a development environment for XrdMon is available in
sub-directory `gled-build`. To use it:

      cd gled-build
      . build_env.sh
     

Now you should be able to use stuff like `make` and `svn` here. To run the
demo as in above example:

      cd demos/XrdMon
      gled xrd_suck_udp.C

To allow for modular building (build only needed libsets) Gled SVN
repository is not single-rooted. `svn update" in the =gled-build` directory
will only update `gled-build` package itself. To update libset XrdMon one
can do `svn up libsets/XrdMon` and its demos `svn up demos/XrdMon` (of
course, one can run SVN commands in subdirectories directly). To update
everything, one can do:

      make svn_update

There were promises from the `subversion` team for better support of custom,
client-side checkout hierarchies like the one used by Gled build. I need to
check what happened there.

From build-system perspective, Gled uses a two-level hierarhical build
structure. So, if one modifies files in `libsets/XrdMon` directory the
`make` command can be run directly in this directory. Top-level make
traverses all libsets configured for building.

-- Main.MatevzTadel - 15 Jul 2012
