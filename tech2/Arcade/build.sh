#!/bin/bash

mkdir build 2>/dev/null

clear

echo -e "[\e[32mArcade\e[39m] Building project..."
cmake -B ./build -S . || exit 1

echo -e "\n[\e[32mArcade\e[39m] Compiling project..."
make -j --no-print-directory -C ./build/ || exit 1

echo -e "\n[\e[32mArcade\e[39m] Executing project..."
./build/arcade $1 || exit 1
