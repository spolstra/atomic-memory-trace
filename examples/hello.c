#include <stdio.h>

#include "src/annotation.h"

int main(void) {
    atomic_trace::start_roi();
    printf("hello\n");
    atomic_trace::end_roi();

    return 0;
}
