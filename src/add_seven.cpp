#include "../include/add_seven.h"




void array_add_seven(const double *in, int size, double *out) {
    for (int i = 0; i < size; ++i) {
        out[i] = in[i] + 7.0;
    }
}


double *direct_add_seven(double *in, int size) {
    auto out = new double[size];
    for (int i = 0; i < size; ++i) {
        out[i] = in[i] + 7.0;
    }
    return out;
}

void double_struct(TestStruct &in, TestStruct &out) {
    out.x = 2 * in.x;
    out.y = 2 * in.y;
}

void sum_two_arrays(TwoArrays &in, OneArray &out) {
    for (unsigned int i = 0; i < in.size; i++) {
        out.x[i] = in.x[i] + in.y[i];
    }
}

void sum_array(OneArray *in, double *out) {
    double accumulator = 0.0;
    for (unsigned int i = 0; i < in->size; i++) {
        accumulator += in->x[i];
    }
    *out = accumulator;
}
