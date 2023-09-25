#include <stdio.h>
#include <omp.h>

#include "src/annotation.h"

int main(void) {
    int sum = 0;

    atomic_trace::start_roi(); // This way we include a lot of openmp overhead
    #pragma omp parallel
    {
        // printf("omp_get_num_threads(): %d\n", omp_get_num_threads());
        // atomic_trace::start_roi(); // needs in roi_per_thread branch
        sum += 1;
        // atomic_trace::end_roi();
    }
    atomic_trace::end_roi(); // This way we include a lot of openmp overhead

    printf("sum: %d\n", sum);
    return 0;
}
