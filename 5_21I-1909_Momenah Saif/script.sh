#!/bin/bash

echo "Script Arguments:"
for arg in "$@"; do
    echo "$arg"
done

echo "Environment Variables:"
env

exit 0
