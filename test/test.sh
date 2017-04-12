#!/bin/bash
#
# Author : fcbruce <fcbruce8964@gmail.com>
#
# Time : Wed 12 Apr 2017 16:54:20
#
#

rm -rf bin build
mkdir bin build
make $1
./bin/$1

