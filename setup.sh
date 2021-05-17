#!/usr/bin/env bash

set -x
set -e

rm -rf build
mkdir build
cd build
cmake .. -DCMAKE_CXX_COMPILER_LAUNCHER=ccache
make -j9
ln -s $PWD/compile_commands.json ..
