#!/bin/bash

declare -A build_times

# Define the builds to run
build_types=("US" "EU" "JP" "DEBUG" "USB")

for type in "${build_types[@]}"; do
    make clean VERSION=$type
    start_time=$(date +%s)
    if make -j VERSION=$type; then
        end_time=$(date +%s)
        elapsed_time=$((end_time - start_time))
        hours=$((elapsed_time / 3600))
        minutes=$(((elapsed_time % 3600) / 60))
        seconds=$((elapsed_time % 60))
        build_times[$type]=$(printf "%02d:%02d:%02d" $hours $minutes $seconds)
    else
        build_times[$type]="failed"
    fi
done

echo "Build results:"
for type in "${build_types[@]}"; do
    echo "$type: ${build_times[$type]}"
done