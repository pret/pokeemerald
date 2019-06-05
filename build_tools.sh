#!/bin/sh
make -C tools/gbagfx CXX=${1:-g++}
make -C tools/scaninc CXX=${1:-g++}
make -C tools/preproc CXX=${1:-g++}
make -C tools/bin2c CXX=${1:-g++}
make -C tools/rsfont CXX=${1:-g++}
make -C tools/aif2pcm CXX=${1:-g++}
make -C tools/ramscrgen CXX=${1:-g++}
make -C tools/gbafix CXX=${1:-g++}
make -C tools/mid2agb CXX=${1:-g++}
make -C tools/mapjson CXX=${1:-g++}
make -C tools/jsonproc CXX=${1:-g++}
