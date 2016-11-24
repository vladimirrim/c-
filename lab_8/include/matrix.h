#ifndef _MATRIX_H_INCLUDED
#define _MATRIX_H_INCLUDED

#include <cstdio>
#include <cstddef>

class Matrix {
public:
    Matrix(std::size_t r, std::size_t c);

    ~Matrix();

    Matrix(const Matrix &that);

    Matrix &operator=(Matrix that);

    std::size_t get_rows();

    std::size_t get_cols();

    void set(std::size_t i, std::size_t j, int val);

    int get(std::size_t i, std::size_t j) const;

    void print(FILE *f) const;

    void swap(Matrix m);

    Matrix operator+(Matrix m) const;

    Matrix operator-(const Matrix &m) const;

    Matrix operator*(const Matrix &m) const;

    Matrix &operator+=(const Matrix &m);

    Matrix &operator-=(const Matrix &m);

    Matrix &operator*=(const Matrix &m);

    bool operator==(const Matrix &m) const;

    bool operator!=(const Matrix &m) const;

private:
    std::size_t _rows;
    std::size_t _cols;
    int **_data;
};

#endif
