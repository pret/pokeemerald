#!/bin/sh
make -C tools/gbagfx
make -C tools/scaninc
make -C tools/preproc
make -C tools/bin2c
make -C tools/rsfont
make -C tools/aif2pcm
make -C tools/ramscrgen
