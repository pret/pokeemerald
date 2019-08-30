#!/bin/sh

echo "This script is deprecated. Next time, run \"make tools\" instead."
for dname in tools/*; do
  if [ -f ${dname}/Makefile ]; then
    make -C ${dname} CXX=${1:-g++} --no-print-directory
  fi
done
