// "Copyright [2022] <tblitzcr>"
#include "./s21_matrix_oop.h"

double S21Matrix::determinant() {
    if (_cols != _rows)
        throw std::out_of_range("Incorrect input, matrix should be square");
    double d = 0;
    if (_rows == 1) {
        d = _p[0][0];
    } else {
        if (_rows == 2) {
            d = _p[0][0] * _p[1][1] -
                    (_p[1][0] * _p[0][1]);
            return d;
        } else if (_rows > 2) {
            int k = 1;
            for (int i = 0; i < _rows; ++i) {
                S21Matrix tmp(_rows-1, _cols-1);
                get_new(*this, &tmp, i, 0);
                double det = tmp.determinant();
                tmp.free_memory();
                d = d + k * _p[i][0] * det;
                k = -k;
            }
        }
    }
    return d;
}
