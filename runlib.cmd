#!/bin/bash
if ! [ -d ~/utblib ]; then mkdir ~/utblib; fi
g++ -fPIC utbDir.cpp utilities.cpp -shared -o ~/utblib/libutbDir.so
g++ -fPIC utbFile.cpp utilities.cpp -shared -o ~/utblib/libutbFile.so
g++ -fPIC utbText.cpp utilities.cpp -shared -o ~/utblib/libutbText.so
g++ -fPIC utbShell.cpp utilities.cpp -shared -o ~/utblib/libutbShell.so
g++ -fPIC utbBegin.cpp pt4utilities.cpp udata.cpp uprint.cpp -shared -o ~/utblib/libutbBegin.so
g++ -fPIC utbMPI1Proc.cpp pt4utilities.cpp udata.cpp uprint.cpp -shared -o ~/utblib/libutbMPI1Proc.so
g++ -fPIC utbMPI2Send.cpp pt4utilities.cpp udata.cpp uprint.cpp -shared -o ~/utblib/libutbMPI2Send.so
g++ -fPIC utbMPI3Coll.cpp pt4utilities.cpp udata.cpp uprint.cpp -shared -o ~/utblib/libutbMPI3Coll.so
g++ -fPIC utbMPI4Type.cpp pt4utilities.cpp udata.cpp uprint.cpp -shared -o ~/utblib/libutbMPI4Type.so
g++ -fPIC utbMPI5Comm.cpp pt4utilities.cpp udata.cpp uprint.cpp -shared -o ~/utblib/libutbMPI5Comm.so