#!/bin/bash

# Root directory of atomic trace library:
# git@github.com:spolstra/atomic-memory-trace.git branch: roi_per_thread
ROOT_DIR=`pwd`


# https://www.intel.com/content/www/us/en/developer/articles/tool/pin-a-binary-instrumentation-tool-downloads.html
PIN_DIR=~/projects/pin

# Compile trace pintool
(cd ${ROOT_DIR}/trace; make PIN_ROOT=${PIN_DIR})

# Compile annotation library
(cd ${ROOT_DIR}/lib; make)

