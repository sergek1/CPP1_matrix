// "Copyright [2022] <tblitzcr>"
#include "./s21_matrix_oop.h"

S21Matrix S21Matrix::inverse_matrix() {
    if (_rows != _cols) throw std::out_of_range(
            "Incorrect input, matrix should be square");
    double det = determinant();
    if (my_fabs(det) < 1e-8) {
        throw std::out_of_range(
                "Inverse matrix doesn't exist. det must not be 0");
    }
    S21Matrix inverse_matrix(*this);
    if (_rows == 1) {
        inverse_matrix._p[0][0] = 1.0/ _p[0][0];
    } else {
        S21Matrix tmp = calc_complements();
        inverse_matrix = tmp.transpose();
        inverse_matrix.mul_number(1.0/det);
        tmp.free_memory();
    }
    return inverse_matrix;
}
