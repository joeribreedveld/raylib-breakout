#include "utils.h"

float ReflectClamp(float *position, float *velocity, float min, float max) {
    if (*position < min) {
        *position = 2 * min - *position;
        *velocity *= -1;
    } else if (*position > max) {
        *position = 2 * max - *position;
        *velocity *= -1;
    }

    return *position;
}
