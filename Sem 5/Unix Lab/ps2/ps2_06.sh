#! /bin/bash

filesize() {
    TOTAL_SIZE=0
    for filename in "$@"; do
        if ! [ -f "$filename" ]; then echo "$filename is not a valid file" && continue; fi
        TOTAL_SIZE=$((TOTAL_SIZE + $(stat -c "%s" "$filename")))
    done
    echo "Total Size(Bytes): $TOTAL_SIZE"
}

filesize $@
