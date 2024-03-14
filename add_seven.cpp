//
// Created by jhellier on 23/01/24.
//

#include "add_seven.h"


int add_seven(int to_add) {
    return to_add + 7;
}

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

void double_struct(TestStruct *in, TestStruct *out) {
    out->x = 2 * in->x;
    out->y = 2 * in->y;
}


