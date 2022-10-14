//  "Copyright [2022] <tblitzcr>"
#include "./s21_matrix_oop.h"

void S21Matrix::allocate_memory() {
    if (_rows < 1 || _cols < 1) throw std::invalid_argument(
                "The matrice should not be empty");
    _p = new double*[_rows];
    for (int i = 0; i < _rows; ++i) {
        _p[i] = new double[_cols];
        for (int j = 0; j < _cols; ++j)
            _p[i][j] = 0;
    }
}

void S21Matrix::free_memory() {
    if (_p) {
        for (int i = 0; i < _rows; ++i)
            delete [] _p[i];
        delete[] _p;
    }
    _rows = 0, _cols = 0, _p = nullptr;
}

double S21Matrix::my_fabs(double num) {
    num = num > 0 ? num: -num;
    return num;
}
