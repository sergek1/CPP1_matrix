// "Copyright [2022] <tblitzcr>"
#include "./s21_matrix_oop.h"

S21Matrix::S21Matrix(int rows, int cols) : _rows(rows), _cols(cols) {
    this->allocate_memory();
}

S21Matrix::S21Matrix(): S21Matrix(3, 3) {}

S21Matrix::S21Matrix(const S21Matrix& o) : S21Matrix(o._rows, o._cols) {
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j)
            _p[i][j] = o._p[i][j];
    }
}

S21Matrix::S21Matrix(S21Matrix&& o) noexcept: S21Matrix(o) {
    o.free_memory();
}

S21Matrix::~S21Matrix() {
    this->free_memory();
}
