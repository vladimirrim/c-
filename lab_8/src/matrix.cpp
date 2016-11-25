#include "matrix.h"
#include <algorithm>


void Matrix::swap(Matrix m) {
    std::swap(_cols, m._cols);
    std::swap(_rows, m._rows);
    std::swap(_data, m._data);
}

Matrix::~Matrix() {
    delete[]_data[0];
    delete[]_data;
}


Matrix::Matrix(std::size_t r, std::size_t c) {
    _data = new int *[r];
    _rows = r;
    _cols = c;
    int *str = new int[r * c];
    for (size_t i = 0; i < r; i++)
        _data[i] = str + c * i;
    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
            _data[i][j] = 0;
}

Matrix::Matrix(const Matrix &that) {
    _cols = that._cols;
    _rows = that._rows;
    _data = new int *[_rows];
    int *str = new int[_rows * _cols];
    for (size_t i = 0; i < _rows; i++)
        _data[i] = str + _cols * i;
    std::copy(&that._data[0][0], &that._data[0][0] + _rows * _cols, &_data[0][0]);
}


Matrix &Matrix::operator=(Matrix that) {
    swap(that);
    return *this;
}

size_t Matrix::get_rows() { return _rows; }

size_t Matrix::get_cols() { return _cols; }

void Matrix::set(std::size_t i, std::size_t j, int val) {
    _data[i][j] = val;
}

int Matrix::get(std::size_t i, std::size_t j) const {
    return _data[i][j];
}

void Matrix::print(FILE *f) const {
    for (size_t i = 0; i < _rows; i++) {
        for (size_t j = 0; j < _cols; j++)
            fprintf(f, "%d ", _data[i][j]);
        fprintf(f, "\n");
    }
}

bool Matrix::operator==(const Matrix &m) const {
    if ( _cols != m._cols || _rows != m._rows )
        return false;
    for (size_t i = 0; i < _rows; i++)
        for (size_t j = 0; j < _cols; j++)
            if ( _data[i][j] != m.get(i, j))
                return false;
    return true;
}

bool Matrix::operator!=(const Matrix &m) const {
    if ( *this == m )
        return false;
    return true;
}

Matrix &Matrix::operator+=(const Matrix &m) {
    for (size_t i = 0; i < _rows; i++)
        for (size_t j = 0; j < _cols; j++)
            _data[i][j] += m.get(i, j);
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &m) {
    for (size_t i = 0; i < _rows; i++)
        for (size_t j = 0; j < _cols; j++)
            _data[i][j] -= m.get(i, j);
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &m) {
    Matrix tmp(_rows, m._cols);
    for (size_t i = 0; i < _rows; i++)
        for (size_t j = 0; j < m._cols; j++) {
            for (size_t k = 0; k < _cols; k++)
                tmp._data[i][j] += _data[i][k] * m.get(k, j);
        }
    *this = tmp;
    return *this;
}

Matrix Matrix::operator+(Matrix m) const {
    return m += *this;
}

Matrix Matrix::operator-(const Matrix &m) const {
    Matrix tmp(*this);
    return tmp -= m;
}

Matrix Matrix::operator*(const Matrix &m) const {
    Matrix tmp(*this);
    return tmp *= m;
}
