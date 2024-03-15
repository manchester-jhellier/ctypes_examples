//
// Created by jhellier on 23/01/24.
//

#ifndef CXX_LIBRARY_TESTS_ADD_SEVEN_H
#define CXX_LIBRARY_TESTS_ADD_SEVEN_H
extern "C" {
void array_add_seven(const double *in, int size, double *out);
}

extern "C" {

int add_seven(int);

double *direct_add_seven(double *in, int size);

struct TestStruct {
    double x;
    int y;
};

struct OneArray{
    unsigned int size;
    double *x;
};

struct TwoArrays{
    unsigned int size;
    double *x, *y;
};

void sum_two_arrays(TwoArrays &in, OneArray &out);

void double_struct(TestStruct &in, TestStruct &out);

}


#endif //CXX_LIBRARY_TESTS_ADD_SEVEN_H
