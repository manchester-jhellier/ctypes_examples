#include "../include/array_seven.h"

void add_seven(std::size_t array_size, double *in, double *out) {
    for (size_t i = 0; i < array_size; ++i) {
        out[i] = in[i] + 7.0;
    }
}
