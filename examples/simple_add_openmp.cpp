#include <stdio.h>
#include <omp.h>

#include "src/annotation.h"

int main(void) {
    int sum = 0;

    #pragma omp parallel
    {
        atomic_trace::start_roi();
        int add = 1;
        atomic_trace::end_roi();

        // critical section adds a lot of tracing for some threads
        #pragma omp critical
        {
            atomic_trace::start_roi();
            sum += add; // race if not in critical section
            atomic_trace::end_roi();
        }
    }

    printf("sum: %d\n", sum);
    return 0;
}
