/*

This program will numerically compute the integral of

                  4/(1+x*x)

from 0 to 1.  The value of this integral is pi -- which
is great since it gives us an easy way to check the answer.

The is the original sequential program.  It uses the timer
from the OpenMP runtime library

History: Written by Tim Mattson, 11/99.

*/
#include <omp.h>
#include <stdio.h>

#include "src/annotation.h"

// For reference
const double PI = 3.14159265358979323846;

static long num_steps = 1000;
double step;
int main() {
    int i;
    double x, pi, sum = 0.0;
    double start_time, run_time;


    step = 1.0 / (double)num_steps;


    start_time = omp_get_wtime();

    atomic_trace::start_roi();
#pragma omp parallel for reduction(+ : sum)
    for (i = 1; i <= num_steps; i++) {
        x = (i - 0.5) * step;
        sum = sum + 4.0 / (1.0 + x * x);
    }
    atomic_trace::end_roi();

    pi = step * sum;
    run_time = omp_get_wtime() - start_time;
    printf("\n pi with %ld steps is %.16lf in %lf seconds\n ", num_steps, pi, run_time);
}

