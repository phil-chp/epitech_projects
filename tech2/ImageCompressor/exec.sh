#!/bin/bash

if [ $# -ne 3 ]; then
    echo -e "USAGE:\n\t$0 <file_name> <color_count> <convergence>"
    exit 1
fi

echo "==> Converting image data..."
./tmp/convertImg "$1" > ./tmp/input

echo "==> Compressing image data..."
./imageCompressor -f ./tmp/input -n "$2" -l "$3" > ./tmp/output

echo "==> Converting image data to XPM image..."
./tmp/xpmImg ./tmp/output
