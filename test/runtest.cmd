#!/bin/bash
LD_LIBRARY_PATH=../utblib
export LD_LIBRARY_PATH
../unixTaskbook -c custom -l ru -t $1
