#!/usr/bin/env bash

../build.sh

cd ../bin/test.app/Contents/MacOS
./test
cd -
