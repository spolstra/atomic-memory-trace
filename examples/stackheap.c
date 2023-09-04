#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <omp.h>
 
#include "src/annotation.h"

int main(void) {

    atomic_trace::start_roi();
    #pragma omp parallel
    {
        int i;
        int *p = (int*) malloc(sizeof(int));
        int *p2 = (int*) malloc(sizeof(int));
        printf("%d: stack address\t%zu\n", omp_get_thread_num(), (uintptr_t) &i);
        printf("%d: heap address\t%zu\n", omp_get_thread_num(), (uintptr_t) p);
        printf("%d: heap address\t%zu\n", omp_get_thread_num(), (uintptr_t) p2);
    }
    atomic_trace::end_roi();

    return 0;
}
