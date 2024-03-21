#ifndef CXX_LIBRARY_TESTS_ARRAY_RECASTING_H
#define CXX_LIBRARY_TESTS_ARRAY_RECASTING_H

#include <vector>
#include <array>

extern "C" {
struct CLikeArray {
    std::size_t num_vecs;
    double *x;
};
void explicit_copy(CLikeArray &in, CLikeArray &out);
void implicit_copy(CLikeArray &in, CLikeArray &out);
}

class VectorStorer {
public:
    std::size_t num_vecs;
    std::vector <std::array<double, 3>> x;

    explicit VectorStorer(std::size_t n);

    explicit VectorStorer(CLikeArray &c_like_array);

    void copy_into_array(CLikeArray &c_like_array);

    static VectorStorer from_array(CLikeArray &c_like_array);
};

extern "C" {
void vec_store_sum(VectorStorer &in_x, VectorStorer &in_y, VectorStorer &out);
void array_sum(CLikeArray &x_in, CLikeArray &y_in, CLikeArray &out);
}

#endif //CXX_LIBRARY_TESTS_ARRAY_RECASTING_H
