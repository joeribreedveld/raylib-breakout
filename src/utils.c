#include "utils.h"

float ReflectClamp(float *pos, float *vel, float min, float max) {
    if (*pos < min) {
        *pos = 2 * min - *pos;
        *vel *= -1;
    } else if (*pos > max) {
        *pos = 2 * max - *pos;
        *vel *= -1;
    }

    return *pos;
}