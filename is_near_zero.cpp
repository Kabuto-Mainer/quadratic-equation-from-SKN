#include <math.h>
#include "is_near_zero.h"

int is_near_zero(double num) {
    if (abs(num) < PRECISION) {
        return 1;
    }
    else {
        return 0;
    }
    return -1;
}
