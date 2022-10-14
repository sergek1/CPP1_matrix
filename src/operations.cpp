// "Copyright [2022] <tblitzcr>"
#include "./s21_matrix_oop.h"

void S21Matrix::sum_matrix(const S21Matrix& o) {
    sum_sub_matrix(o, SUM);
}

void S21Matrix::sub_matrix(const S21Matrix& o) {
    sum_sub_matrix(o, SUB);
}

void S21Matrix::sum_sub_matrix(const S21Matrix& o, int flag) {
    if ((_rows != o._rows || _cols != o._cols)) throw std::out_of_range(
                "Incorrect input, matrices should have the same size");
    for (int i = 0; i < o._rows; i++) {
        for (int j = 0; j < o._cols; ++j) {
            if (flag == SUM)
                _p[i][j] += o._p[i][j];
            if (flag == SUB)
                _p[i][j] -= o._p[i][j];
        }
    }
}

void S21Matrix::mul_number(const double num) {
    for (auto i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; ++j)
            _p[i][j] *= num;
    }
}
void S21Matrix::mul_matrix(const S21Matrix& other) {
    if (_cols != other._rows) throw std::out_of_range(
                "Incorrect input, matrice1 should have the same number"
                " of columns as the number of rows of matrice2");
    S21Matrix tmp(*this);
    free_memory();
    _rows = tmp._rows; _cols = other._cols;
    allocate_memory();
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            _p[i][j] = 0;
            for (int k = 0; k < tmp._cols; ++k)
                _p[i][j] += (tmp._p[i][k] * other._p[k][j]);
        }
    }
    tmp.free_memory();
}

bool S21Matrix::eq_matrix(const S21Matrix& other) {
    bool choice = true;
    if (_rows == other._rows && _cols == other._cols) {
        bool flag = true;
        for (int i = 0; i < _rows && flag == 1; ++i) {
            for (int j = 0; j < _cols; ++j) {
                if (my_fabs(_p[i][j] - other._p[i][j]) > EPS)
                    flag = false;
            }
        }
        if (!flag)
            choice = false;
    } else {
        choice = false;
    }
    return choice;
}

S21Matrix S21Matrix::transpose() {
    S21Matrix new_matrix(_cols, _rows);
    for (int i = 0; i < new_matrix._rows; ++i) {
        for (int j = 0; j < new_matrix._cols; ++j)
            new_matrix._p[i][j] = _p[j][i];
    }
    return new_matrix;
}
