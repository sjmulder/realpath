OpenBSD realpath(1)
===================
A portable version of OpenBSD's
[realpath](https://man.openbsd.org/realpath.1) utility,
a wrapper for the
[realpath()](https://man.openbsd.org/realpath.3) function.

Installing
----------
    make
    make install   [DESTDIR=] [PREFIX=/usr/local] [MANPREFIX=${PREFIX}/man]
    make uninstall [DESTDIR=] [PREFIX=/usr/local] [MANPREFIX=${PREFIX}/man]

The utility is pledged by default on OpenBSD only. If your platform has
[pledge()](https://man.openbsd.org/pledge.2) support, add `-D HAVE_PLEDGE=1`
to `CFLAGS` in the environment or on the *make* command line.

License
-------
ISC license. Originally written by Klemens Nanni (<kn@openbsd.org>). See
source files.
