#include <stdio.h>

#include "src/annotation.h"

int main(void) {
    int i = 0;
    atomic_trace::start_roi();
    i = i + 1;
    atomic_trace::end_roi();

    return 0;
}
