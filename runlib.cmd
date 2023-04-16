#!/bin/bash
if ! [ -d ./utblib ]; then mkdir ./utblib; fi
g++ -fPIC -std=c++17 -Wno-attributes src/utbDir.cpp src/utilities.cpp -shared -o ./utblib/libutbDir.so
g++ -fPIC -std=c++17 -Wno-attributes src/utbFile.cpp src/utilities.cpp -shared -o ./utblib/libutbFile.so
g++ -fPIC -std=c++17 -Wno-attributes src/utbText.cpp src/utilities.cpp -shared -o ./utblib/libutbText.so
g++ -fPIC -std=c++17 -Wno-attributes src/utbShell.cpp src/utilities.cpp -shared -o ./utblib/libutbShell.so
g++ -fPIC -std=c++17 -Wno-attributes src/utbBegin.cpp src/pt4utilities.cpp src/udata.cpp src/uprint.cpp -shared -o ./utblib/libutbBegin.so
g++ -fPIC -std=c++17 -Wno-attributes src/utbMPI1Proc.cpp src/pt4utilities.cpp src/udata.cpp src/uprint.cpp /usr/local/lib/libyaml-cpp.a -shared -o ./utblib/libutbMPI1Proc.so
g++ -fPIC -std=c++17 -Wno-attributes src/utbMPI2Send.cpp src/pt4utilities.cpp src/udata.cpp src/uprint.cpp -shared -o ./utblib/libutbMPI2Send.so
g++ -fPIC -std=c++17 -Wno-attributes src/utbMPI3Coll.cpp src/pt4utilities.cpp src/udata.cpp src/uprint.cpp -shared -o ./utblib/libutbMPI3Coll.so
g++ -fPIC -std=c++17 -Wno-attributes src/utbMPI4Type.cpp src/pt4utilities.cpp src/udata.cpp src/uprint.cpp -shared -o ./utblib/libutbMPI4Type.so
g++ -fPIC -std=c++17 -Wno-attributes src/utbMPI5Comm.cpp src/pt4utilities.cpp src/udata.cpp src/uprint.cpp -shared -o ./utblib/libutbMPI5Comm.so
