#include <stdio.h>
#include <omp.h>

#include "src/annotation.h"

int main(void) {
    int sum = 0;

    // race condition!
    #pragma omp parallel
    {
        // printf("omp_get_num_threads(): %d\n", omp_get_num_threads());
        atomic_trace::start_roi();
        sum += 1;
        atomic_trace::end_roi();
    }

    printf("sum: %d\n", sum);
    return 0;
}
