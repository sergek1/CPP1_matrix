// "Copyright [2022] <tblitzcr>"
#include "./s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& o) {
    S21Matrix res(*this);
    res.sum_matrix(o);
    return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& o) {
    S21Matrix res(*this);
    res.sub_matrix(o);
    return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
    S21Matrix res(*this);
    res.mul_matrix(other);
    return res;
}

S21Matrix S21Matrix::operator*(const double num) {
    S21Matrix res(*this);
    res.mul_number(num);
    return res;
}

S21Matrix operator*(double num, const S21Matrix& o) {
    S21Matrix res(o);
    res.mul_number(num);
    return res;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& o) {
    free_memory();
    _rows = o._rows, _cols = o._cols;
    allocate_memory();
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j)
            _p[i][j] = o._p[i][j];
    }
    return *this;
}

bool S21Matrix::operator==(const S21Matrix &o) {
    return eq_matrix(o);
}

void S21Matrix::operator+=(const S21Matrix &o) {
    sum_matrix(o);
}

void S21Matrix::operator-=(const S21Matrix &o) {
    sub_matrix(o);
}

void S21Matrix::operator*=(const S21Matrix &o) {
    if (eq_matrix(o)) {
        S21Matrix o1(std::move(o));
        mul_matrix(o1);
    } else {
        mul_matrix(o);
    }
}
void S21Matrix::operator*=(const double num) {
    mul_number(num);
}

double & S21Matrix::operator()(int row, int col) {
    if (row >= _rows || col >= _cols || row < 0 || col < 0)
        throw std::out_of_range("Incorrect input, index is out of range");
    return _p[row][col];
}
