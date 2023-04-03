#!/bin/bash
LD_LIBRARY_PATH=~/utblib
export LD_LIBRARY_PATH
cd test
../unixTaskbook -t $1
