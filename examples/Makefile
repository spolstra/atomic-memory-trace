CXX=g++
CC=gcc
CFLAGS=-I/home/spolstra/projects/atomic-memory-trace -O0
LDFLAGS=-L/home/spolstra/projects/atomic-memory-trace/lib -lannotation
PIN=~/projects/pin
ATOMIC_MEM=/home/spolstra/projects/atomic-memory-trace

stackheap: stackheap.c
	$(CXX) -o $@ $< $(CFLAGS) $(LDFLAGS) -fopenmp

simple_add_openmp_cpp: simple_add_openmp.cpp
	$(CXX) -o $@ $< $(CFLAGS) $(LDFLAGS) -fopenmp

simple_add_openmp: simple_add_openmp.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) -fopenmp

pi_parallel: pi_parallel.c
	$(CXX) -o $@ $< $(CFLAGS) $(LDFLAGS) -fopenmp

matrix_mult: matrix_mult.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) -fopenmp

matrix_mult_annot: matrix_mult_annot.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) -fopenmp

hello: hello.c
	$(CXX) -o $@ $< $(CFLAGS) $(LDFLAGS)

simple_add: simple_add.c
	$(CXX) -o $@ $< $(CFLAGS) $(LDFLAGS)

run_simple_add: simple_add
	$(PIN)/pin -t $(ATOMIC_MEM)/trace/obj-intel64/trace.so -i -- ./$<
	
run_simple_add_openmp_cpp: simple_add_openmp_cpp
	$(PIN)/pin -t $(ATOMIC_MEM)/trace/obj-intel64/trace.so -i -- ./$<

run_simple_add_openmp: simple_add_openmp
	$(PIN)/pin -t $(ATOMIC_MEM)/trace/obj-intel64/trace.so -i -- ./$<

run_pi_parallel: pi_parallel
	$(PIN)/pin -t $(ATOMIC_MEM)/trace/obj-intel64/trace.so -i -- ./$<

run_stackheap: stackheap
	$(PIN)/pin -t $(ATOMIC_MEM)/trace/obj-intel64/trace.so -i -- ./$<

run_matrix_mult_annot: matrix_mult_annot
	$(PIN)/pin -t $(ATOMIC_MEM)/trace/obj-intel64/trace.so -i -- ./$<

clean:
	rm -f simple_add simple_add_openmp simple_add_openmp_cpp matrix_mult matrix_mult_annot hello *.o *.out
