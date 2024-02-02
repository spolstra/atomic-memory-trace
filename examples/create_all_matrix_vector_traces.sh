#!/bin/bash

TOOLDIR=/home/spolstra/projects/psa-tools

create_traces() {
    M=$1
    N=$2
    TRACEBASE="matrix_vector_${M}_${N}"
    for P in 1 2 4 8; do
        echo "Running P=$P M=$M N=$N make run_matrix_vector_mult"
        P=$P M=$M N=$N make run_matrix_vector_mult
        $TOOLDIR/alignment_filter_4bytes.py memory_trace.out > filtered.out
        $TOOLDIR/atomic_trace_converter.py filtered.out ${TRACEBASE}_p${P}.trf
    done
}

rm -f memory_trace.out filtered.out
M=200
N=200
echo "Creating: ${M}x${N}..."
create_traces $M $N

rm -f memory_trace.out filtered.out
M=8
N=5000
echo "Creating: ${M}x${N}..."
create_traces $M $N

rm -f memory_trace.out filtered.out
M=5000
N=8
echo "Creating: ${M}x${N}..."
create_traces $M $N


