#!/bin/sh
# @(#)cc-config.sh	1.2 02/05/19 Copyright 2002 J. Schilling
###########################################################################
# Written 2002 by J. Schilling
###########################################################################
# Configuration script called to verify system default C-compiler.
# It tries to fall back to GCC if the system default could not be found.
###########################################################################
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING.  If not, write to
# the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
###########################################################################

CC=$1
echo "Trying to find $CC"
#
# There are old shells that don't support the 'type' builtin.
# For this reason it is not a simple task to find out whether
# this compiler exists and works.
#
# First try to run the default C-compiler without args
#
$CC > /dev/null 2>&1
if [ $? = 0 ]; then
	echo "Found $CC"
	echo "Creating empty '$2'"
	:> $2
	exit
fi

#
# Now try to run the default C-compiler and check whether it creates
# any output (usually an error message).
#
# This test will fail if the shell does redirect the error message
# "cc: not found". All shells I tested (except ksh) send this message to
# the stderr stream the shell itself is attached to and only redirects the
# output from the command. As there may no output if there is no binary,
# this prooves the existence of the default compiler.
#
ccout=`$CC 2>&1`
ret=$?

nf=`echo "$ccout" | grep 'not found' `
if [ $ret = 127 -a -n "$nf" ]; then
	#
	# ksh redirects even the error message from the shell, but we
	# see that there is no executable because the exit code is 127
	#
	ccout=""
fi

if [ -n "$ccout" ]; then
	echo "Found $CC"
	echo "Creating empty '$2'"
	:> $2
	exit
fi

#
# If the current default is gcc, try cc.
# If the current default is cc, try gcc.
#
if [ ".$CC" = ".gcc" ]; then
	XCC=cc
	echo 'Trying to find cc'
	ccout=`cc -c tt.$$.c 2>&1`
	ret=$?
	nf=`echo "$ccout" | grep 'not found' `
	if [ $ret = 127 -a -n "$nf" ]; then
		#
		# ksh redirects even the error message from the shell, but we
		# see that there is no executable because the exit code is 127
		#
		ccout=""
	fi
	if [ -n "$ccout" ]; then
		CC=cc
	fi
else
	XCC=xcc
	echo 'Trying to find GCC'
	gcc -v 2> /dev/null && CC=gcc
fi

if [ ".$CC" = ".$1" ]; then
	echo "$XCC not found, keeping current global default"
	echo "Creating empty '$2'"
	:> $2
else
	echo "Found $CC"
	echo "Making $CC the default compiler in '$2'"
	echo DEFCCOM=$CC > $2
fi
