#!/bin/bash

# Starting index
start=1

# Ending index
end=22

# Base directory name
basename="q"

# Suffix for the copy directory
copy_suffix=" copy"

for ((i=start; i<=end; i++)); do
    # Format the directory index with leading zero if less than 10
    dir_index=$(printf "%02d" $i)
    
    # Construct the directory name
    dir_name="${basename}${dir_index}"

    # Remove the existing directory
    echo "Removing $dir_name"
    rm -rf "$dir_name"

    # Copy the 'q01 copy' directory to the new directory
    echo "Copying q01 copy to $dir_name"
    cp -r "'q01${copy_suffix}'" "$dir_name"
done

echo "Operation completed for directories q01 to q22."

