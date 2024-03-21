#include "array_recasting.h"

VectorStorer::VectorStorer(std::size_t n) {
    num_vecs = n;
    for (int i = 0; i < num_vecs; ++i) {
        x.push_back({0.0, 0.0, 0.0});
    }
}

VectorStorer::VectorStorer(CLikeArray &c_like_array) {
    num_vecs = c_like_array.num_vecs;
    x = std::vector < std::array < double, 3 >> (reinterpret_cast<std::array<double, 3> *>(c_like_array.x),
            reinterpret_cast<std::array<double, 3> *>(c_like_array.x) + num_vecs);
}

void VectorStorer::copy_into_array(CLikeArray &c_like_array) {
    for (std::size_t i = 0; i < num_vecs; ++i) {
        for (std::size_t j = 0; j < 3; ++j) {
            c_like_array.x[3 * i + j] = x[i][j];
        }
    }
}

VectorStorer VectorStorer::from_array(CLikeArray &c_like_array) {
    auto vec_store = VectorStorer(c_like_array.num_vecs);
    for (std::size_t i = 0; i < c_like_array.num_vecs; ++i) {
        for (std::size_t j = 0; j < 3; ++j) {
            vec_store.x[i][j] = c_like_array.x[3 * i + j];
        }
    }
    return vec_store;
}

void explicit_copy(CLikeArray &in, CLikeArray &out) {
    auto vec_store = VectorStorer::from_array(in);
    vec_store.copy_into_array(out);
}

void implicit_copy(CLikeArray &in, CLikeArray &out) {
    auto vec_store = VectorStorer(in);
    vec_store.copy_into_array(out);
}

void vec_store_sum(VectorStorer &in_x, VectorStorer &in_y, VectorStorer &out) {
    for (std::size_t i = 0; i < in_x.num_vecs; ++i) {
        for (std::size_t j = 0; j < 3; ++j) {
            out.x[i][j] = in_x.x[i][j] + in_y.x[i][j];
        }
    }
}

void array_sum(CLikeArray &x_in, CLikeArray &y_in, CLikeArray &out) {
    auto u = VectorStorer(x_in);
    auto v = VectorStorer(y_in);
    auto w = VectorStorer(out);
    vec_store_sum(u, v, w);
}
