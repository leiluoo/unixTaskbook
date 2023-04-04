#!/bin/bash
if ! [ -d ~/utblib ]; then mkdir ~/utblib; fi
g++ -fPIC src/utbDir.cpp src/utilities.cpp -shared -o ~/utblib/libutbDir.so
g++ -fPIC src/utbFile.cpp src/utilities.cpp -shared -o ~/utblib/libutbFile.so
g++ -fPIC src/utbText.cpp src/utilities.cpp -shared -o ~/utblib/libutbText.so
g++ -fPIC src/utbShell.cpp src/utilities.cpp -shared -o ~/utblib/libutbShell.so
g++ -fPIC src/utbBegin.cpp src/pt4utilities.cpp src/udata.cpp src/uprint.cpp -shared -o ~/utblib/libutbBegin.so
g++ -fPIC src/utbMPI1Proc.cpp src/pt4utilities.cpp src/udata.cpp src/uprint.cpp -shared -o ~/utblib/libutbMPI1Proc.so
g++ -fPIC src/utbMPI2Send.cpp src/pt4utilities.cpp src/udata.cpp src/uprint.cpp -shared -o ~/utblib/libutbMPI2Send.so
g++ -fPIC src/utbMPI3Coll.cpp src/pt4utilities.cpp src/udata.cpp src/uprint.cpp -shared -o ~/utblib/libutbMPI3Coll.so
g++ -fPIC src/utbMPI4Type.cpp src/pt4utilities.cpp src/udata.cpp src/uprint.cpp -shared -o ~/utblib/libutbMPI4Type.so
g++ -fPIC src/utbMPI5Comm.cpp src/pt4utilities.cpp src/udata.cpp src/uprint.cpp -shared -o ~/utblib/libutbMPI5Comm.so