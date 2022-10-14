// "Copyright [2022] <tblitzcr>"
#include "./s21_matrix_oop.h"

S21Matrix S21Matrix::calc_complements() {
    if (_rows != _cols)
        throw std::out_of_range("Incorrect input, matrix should be square");
    S21Matrix new_matrix(_rows, _cols);
    if (_rows == 1) {
        new_matrix(0, 0) = _p[0][0];
    } else {
        S21Matrix b(_rows - 1, _cols - 1);
        for (int i = 0; i < new_matrix._rows; ++i) {
            for (int j = 0; j < new_matrix._cols; ++j)
                new_matrix._p[i][j] = _p[i][j];
        }
        for (int i = 0; i < new_matrix._rows; ++i) {
            for (int j = 0; j < new_matrix._cols; ++j) {
                get_new(*this, &b, i, j);
                if ((i + 1 + j + 1) % 2 == 1)
                    new_matrix._p[i][j] = -b.determinant();
                else
                    new_matrix._p[i][j] = b.determinant();
            }
        }
        b.free_memory();
    }
    return new_matrix;
}
void S21Matrix::get_new(const S21Matrix &matrix, S21Matrix *tmp,
                        int i, int j) {
    int di = 0;
    tmp->_rows = matrix._rows, tmp->_cols = matrix._cols;
    for (int ki = 0; ki < matrix._rows - 1; ++ki) {
        if (ki == i)
            di = 1;
        int dj = 0;
        for (int kj = 0; kj < matrix._rows - 1; ++kj) {
            if (kj == j)
                dj = 1;
            tmp->_p[ki][kj] = matrix._p[ki + di][kj + dj];
        }
    }
    tmp->_rows -= 1, tmp->_cols -= 1;
}
