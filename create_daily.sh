#!/bin/bash

SOURCE_DIR="Daily"
DEST_DIR="DailyRuns"
PREFIX="Daily"

# Go to the destination directory
cd "$DEST_DIR" || exit

# Find the highest numbered Daily folder
highest_num=$(ls | grep "^${PREFIX}[0-9]*$" | sed "s/^${PREFIX}//" | sort -n | tail -n 1)

# If no folders found, start numbering from 1, else increment by 1
if [ -z "$highest_num" ]; then
    next_num=1
else
    next_num=$((highest_num + 1))
fi

# Copy the source directory to the new destination directory
cp -r "../$SOURCE_DIR" "${PREFIX}${next_num}"

# Return to the original directory
cd -
