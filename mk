#!/bin/sh

#
# Run the make command on an OS specifi.c file, or just "Makefile" if no OS
# specific file is found
#


if [ -f Makefile.`uname -s` ]
then
	make -f Makefile.`uname -s` "$@"
else
	make "$@"
fi

