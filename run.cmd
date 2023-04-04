#!/bin/bash
g++ src/main.cpp src/unixTaskbook.cpp src/utilities.cpp src/tasklib.cpp src/error.cpp src/service.cpp -o unixTaskbook -ldl