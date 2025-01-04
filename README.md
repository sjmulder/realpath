This repository has **moved** to:

https://codeberg.org/sjmulder/realpath

The GitHub repository will be deleted in time.
___

OpenBSD realpath(1)
===================
A portable version of OpenBSD's
[realpath](https://man.openbsd.org/realpath.1) utility,
a wrapper for the
[realpath()](https://man.openbsd.org/realpath.3) function.

This edition is versioned independently from OpenBSD, starting at 1.0
and using a regular major/minor/patch scheme.

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
ISC license. Originally written by Klemens Nanni (<kn@openbsd.org>).
See source files. This portable version is maintained by Sijmen J.
Mulder (<ik@sjmulder.nl>).
