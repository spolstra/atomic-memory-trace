CXX=g++
CFLAGS=-I/home/spolstra/projects/atomic-memory-trace -O0
LDFLAGS=-L/home/spolstra/projects/atomic-memory-trace/lib -lannotation
PIN=~/projects/pin
ATOMIC_MEM=/home/spolstra/projects/atomic-memory-trace

simple_add_openmp: simple_add_openmp.c
	$(CXX) -o $@ $< $(CFLAGS) $(LDFLAGS) -fopenmp

hello: hello.c
	$(CXX) -o $@ $< $(CFLAGS) $(LDFLAGS)

simple_add: simple_add.c
	$(CXX) -o $@ $< $(CFLAGS) $(LDFLAGS)

run_simple_add: simple_add
	$(PIN)/pin -t $(ATOMIC_MEM)/trace/obj-intel64/trace.so -i -- ./$<
	
run_simple_add_openmp: simple_add_openmp
	$(PIN)/pin -t $(ATOMIC_MEM)/trace/obj-intel64/trace.so -i -- ./$<

clean:
	rm -f simple_add simple_add_openmp hello *.o *.out
