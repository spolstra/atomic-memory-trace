#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>

#include "src/annotation.h"

#define N 10

// for i in 1 2 4 8 12 16 32; do echo -n "$i threads: "; OMP_NUM_THREADS=$i ./matrix_mult; done

int A[N][N];
int B[N][N];
int C[N][N];

// Only trace computation, all OMP stuff excluded.
// Include init so we have two parallel for loops.

int main() 
{
    int i,j,k;
    struct timeval tv1, tv2;
    struct timezone tz;
	double elapsed; 
    // omp_set_num_threads(omp_get_num_procs());
    // printf("Running on %d threads\n", omp_get_num_threads());

    gettimeofday(&tv1, &tz);

    #pragma omp parallel for private(i,j) shared(A,B)
    for (i= 0; i< N; i++) {
        start_roi();
        for (j= 0; j< N; j++) {
            A[i][j] = 2;
            B[i][j] = 2;
        }
        end_roi();
    }

    #pragma omp parallel for private(i,j,k) shared(A,B,C)
    for (i = 0; i < N; ++i) {
        start_roi();
        for (j = 0; j < N; ++j) {
            for (k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
        end_roi();
    }

    gettimeofday(&tv2, &tz);
    elapsed = (double) (tv2.tv_sec-tv1.tv_sec) + (double) (tv2.tv_usec-tv1.tv_usec) * 1.e-6;
    printf("elapsed time = %f seconds.\n", elapsed);

    for (i= 0; i< N; i++)
    {
        for (j= 0; j< N; j++)
        {
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
}
