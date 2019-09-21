#!/bin/sh
# -*- coding: utf-8 -*-

if [ "$1" = '' ]; then
	echo 'No archive specified to install. Exiting...';
	exit 2;
fi

if [ ! -f "$1" ]; then
	echo "Archive $1 does not exist or access is denied. Exiting...";
	exit 2;
fi

if [ "$(id -u)" != '0' ]; then
	_sudo='sudo ';
else
	_sudo='';
fi

_cwd="${PWD}";

cd /;
${_sudo} tar -xvf "${_cwd}/$1";
cd "${_cwd}";

unset _sudo _cwd;
