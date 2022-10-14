//  "Copyright [2022] <tblitzcr>"
#include "./s21_matrix_oop.h"

int S21Matrix::get_row() {
    return _rows;
}

int S21Matrix::get_col() {
    return _cols;
}

void S21Matrix::set_row(int row) {
    if (row == 0) throw std::invalid_argument( "The row should not equal 0");
    if (row != _rows) {
        S21Matrix tmp(*this);
        free_memory();
        _rows = row; _cols = tmp._cols;
        allocate_memory();
        if (_rows <= tmp._rows) {
            for (int i = 0; i < _rows; ++i) {
                for (int j = 0; j < _cols; ++j)
                    _p[i][j] = tmp._p[i][j];
            }
        } else {
            for (int i = 0; i < tmp._rows; ++i) {
                for (int j = 0; j < _cols; ++j)
                    _p[i][j] = tmp._p[i][j];
            }
            for (int i = tmp._rows; i < _rows; ++i) {
                for (int j = 0; j < _cols; ++j)
                    _p[i][j] = 0;
            }
        }
        tmp.free_memory();
    }
}

void S21Matrix::set_col(int col) {
    if (col == 0) throw std::invalid_argument( "The column should not equal 0");
    if (col != _cols) {
        S21Matrix tmp(*this);
        free_memory();
        _rows = tmp._rows; _cols = col;
        allocate_memory();
        if (_cols <= tmp._cols) {
            for (int i = 0; i < _rows; ++i) {
                for (int j = 0; j < _cols; ++j)
                    _p[i][j] = tmp._p[i][j];
            }
        } else {
            for (int i = 0; i < _rows; ++i) {
                for (int j = 0; j < tmp._cols; ++j)
                    _p[i][j] = tmp._p[i][j];
            }
            for (int i = 0; i < _rows; ++i) {
                for (int j = tmp._cols; j < _cols; ++j)
                    _p[i][j] = 0;
            }
        }
        tmp.free_memory();
    }
}

void S21Matrix::set_row_col(int row, int col) {
    if (row == 0 && col == 0) throw std::invalid_argument(
            "The row and column should not equal 0");
    set_row(row);
    set_col(col);
}
