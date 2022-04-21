DESTDIR?=
PREFIX=?	/usr/local
MANPREFIX=?	${PREFIX}/share

CFLAGS+=	-Wall -Wextra

all: realpath

clean:
	rm -f realpath

install:
	install -d ${DESTDIR}${PREFIX}/bin ${DESTDIR}${MANPREFIX}/man1
	install -m755 realpath  ${DESTDIR}${PREFIX}/bin/
	install -m644 realpath.1 ${DESTDIR}${MANPREFIX}/man1/

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/realpath
	rm -f ${DESTDIR}${MANPREFIX}/man1/realpath.1

.PHONY:
	clean install uninstall
