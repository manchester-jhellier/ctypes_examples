#ifndef CXX_LIBRARY_TESTS_ADD_SEVEN_H
#define CXX_LIBRARY_TESTS_ADD_SEVEN_H


extern "C" {
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
void sum_array(OneArray *in, double *out);
void double_struct(TestStruct &in, TestStruct &out);

}


#endif //CXX_LIBRARY_TESTS_ADD_SEVEN_H
