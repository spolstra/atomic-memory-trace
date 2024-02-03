#!/bin/bash

TOOLDIR=/home/spolstra/projects/psa-tools

if [ $# -ne 1 ]; then
    TARGET="run_matrix_mult_annot"
else
    TARGET=$1
fi

echo "using target: $TARGET"

create_traces() {
    TRACEBASE="matrix_mult_50_50"
    for P in 1 2 4 8; do
        echo "Running P=$P make $TARGET"
        P=$P make $TARGET
        $TOOLDIR/alignment_filter_4bytes.py memory_trace.out > filtered.out
        $TOOLDIR/atomic_trace_converter.py filtered.out ${TRACEBASE}_p${P}.trf
    done
}

rm -f memory_trace.out filtered.out
echo "Creating: matrix mult traces"
create_traces