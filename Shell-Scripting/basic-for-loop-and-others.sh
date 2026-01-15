#!/bin/sh

# Go to the each directory of Music Folder and prints the content of the each folder.

# Colors:
RED='\033[31m'
NC='\033[0m'

PARENT_DIR="$HOME/Music"

cd $PARENT_DIR 2> /dev/null || { echo "Can't find $PARENT_DIR"; exit 1; }

for dir in */; do
    formatted_dir_name=${dir%/} 
    # '%/' remove the '/' of 'dir' variable
    uppercase_dir_name=$(echo "${formatted_dir_name}" | tr '[:lower:]' '[:upper:]')
    # uppercase the entire value using 'tr'(translate) via command substitution
    echo -e "${RED}CONTENT OF ${uppercase_dir_name}${NC}:"
    # We use -e flag to interpret the blackslash escapes(\).
    cd $dir && ls 
    echo ""
    cd ..
done
