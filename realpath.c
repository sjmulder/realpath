/*	$OpenBSD: realpath.c,v 1.1 2021/10/13 15:04:53 kn Exp $ */
/*
 * Copyright (c) 2021 Klemens Nanni <kn@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <err.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <unistd.h>

#if !defined(HAVE_PLEGE) && defined(__OpenBSD__)
# define HAVE_PLEDGE 1
#endif

static char *argv0;

noreturn void
usage(void)
{
	fprintf(stderr, "usage: %s [-q] file\n", argv0);
	exit(1);
}

int
main(int argc, char *argv[])
{
	int ch, qflag = 0;
	char *buf;

	argv0 = argv[0];

#ifdef HAVE_PLEDGE
	if (pledge("stdio rpath", NULL) == -1)
		err(1, "pledge");
#endif

	while ((ch = getopt(argc, argv, "q")) != -1) {
		switch (ch) {
		case 'q':
			qflag = 1;
			break;
		default:
			usage();
		}
	}
	argc -= optind;
	argv += optind;
	if (argc != 1)
		usage();

	buf = realpath(argv[0], NULL);
	if (buf == NULL) {
		if (qflag)
			return (1);
		err(1, "%s", argv[0]);
	}

	printf("%s\n", buf);
	return (0);
}
