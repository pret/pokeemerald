#!/bin/sh
# -*- coding: utf-8 -*-
## Convenience script for installing all the tools at once

REPO='https://pkg.caveoforig.in/fhtk/';

if [ "$(uname -s)" = 'Darwin' ]; then
	TRIPLE='x86_64-apple-darwin';
else
	TRIPLE='x86_64-linux-gnu';
fi

for tool in agbcc aif2pcm gbafix gbagfx jsonproc mapjson mid2agb preproc ramscrgen rsfont scaninc; do
	curl -o"${tool}-${TRIPLE}.tar.xz" "${REPO}/${tool}-${TRIPLE}.tar.xz";
	./util/install.sh "${tool}-${TRIPLE}.tar.xz";
done

unset REPO TRIPLE tool;
