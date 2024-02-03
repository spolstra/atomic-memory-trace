#!/bin/bash

if [ $# -ne 1 ]; then
    echo "usage: $0 trace_base"
    exit 1
fi

TRACE=$1

for F in `ls $TRACE*`; do
    echo $F
    for tid in `~/projects/psa-tools/trace_printer.64.py $F | \
                awk '{print $1}' | grep P | sort | uniq`; do
        echo -n "$tid: "; ~/projects/psa-tools/trace_printer.64.py $F | \
                grep $tid | wc -l ;
    done
done
