#!/bin/bash
LD_LIBRARY_PATH=../utblib
export LD_LIBRARY_PATH
../unixTaskbook -c white -l en -t $1
