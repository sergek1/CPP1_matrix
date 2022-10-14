// "Copyright [2022] <tblitzcr>"

#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <iostream>

class S21Matrix {
 public:
    S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& o);
    S21Matrix(S21Matrix&& o) noexcept;
    ~S21Matrix();

    S21Matrix& operator=(const S21Matrix& o);
    double& operator()(int row, int col);
    S21Matrix operator+(const S21Matrix& o);
    S21Matrix operator-(const S21Matrix& o);

    S21Matrix operator*(const S21Matrix& o);
    S21Matrix operator*(const double num);
    friend S21Matrix operator*(double num, const S21Matrix& o);

    void operator+=(const S21Matrix& o);
    void operator-=(const S21Matrix& o);
    void operator*=(const S21Matrix& o);
    void operator*=(const double num);
    bool operator==(const S21Matrix& o);

    bool eq_matrix(const S21Matrix& o);
    void sum_matrix(const S21Matrix& o);
    void sub_matrix(const S21Matrix& o);
    void mul_number(const double num);
    void mul_matrix(const S21Matrix& other);
    S21Matrix transpose();
    S21Matrix calc_complements();
    double determinant();
    S21Matrix inverse_matrix();

    int get_col();
    int get_row();
    void set_row(int row);
    void set_col(int col);
    void set_row_col(int row, int col);

 private:
    int _rows, _cols;
    double **_p;

    static const int SUB = 1;
    static const int SUM = 0;
    constexpr static const double EPS = 1e-7;
    void allocate_memory();
    void free_memory();
    void sum_sub_matrix(const S21Matrix& o, int flag);
    double my_fabs(double num);
    void get_new(const S21Matrix& matrix, S21Matrix *tmp, int i, int j);
};

#endif  //  SRC_S21_MATRIX_OOP_H_
