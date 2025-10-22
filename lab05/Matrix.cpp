//
// Created by cefgo on 15/10/2025.
//

#include "Matrix.h"

Matrix::Matrix(int rows, int cols) {
    this -> mCols = cols;
    this -> mRows = rows;
    this -> mElements.resize(rows*cols, 0);
}

Matrix::Matrix(const Matrix &other) {
    this -> mCols = other.getCols();
    this -> mRows = other.getRows();
    this -> mElements = other.mElements;
}

Matrix::Matrix(Matrix &&other) noexcept {
    this -> mCols = other.getCols();
    this -> mRows = other.getRows();
    other.mRows = 0;
    other.mCols = 0;
    this -> mElements = (other.mElements);
    other.mElements.clear();
}

Matrix & Matrix::operator=(const Matrix &other) {
    if (this != &other) {
        this -> mRows = other.mRows;
        this -> mCols = other.mCols;
        this -> mElements = other.mElements;
    }
    return *this;
}

Matrix & Matrix::operator=(Matrix &&other) noexcept {
    if (this != &other) {
        this -> mCols = other.getCols();
        this -> mRows = other.getRows();
        other.mRows = 0;
        other.mCols = 0;
        this -> mElements = (other.mElements);
        other.mElements.clear();
    }
    return *this;
}

void Matrix::fillMatrix(double value) {
    fill(this->mElements.begin(),this->mElements.end(),value);
}

void Matrix::randomMatrix(int a, int b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(a,b);
    for (int i = 0; i < this->mRows; i++) {
        for (int j = 0;j < this->mCols; j++) {
            this->mElements[i*mCols+j] = dist(gen);
        }
    }
}

void Matrix::printMatrix(std::ostream &os) const {
    for (int i = 0; i < this -> mRows; ++i) {
        for (int j = 0; j < this -> mCols; ++j) {
            os << this->mElements[i*this->mCols+j] << " ";
        }
        os << endl;
    }
}

double * Matrix::operator[](int row) {
    if (row >= this->mRows || row < 0) {
        throw out_of_range("Out of bounds!");
    }
    return &this->mElements[row*this->mCols];
}

const double * Matrix::operator[](int row) const {
    if (row >= this->mRows || row < 0) {
        throw out_of_range("Out of bounds!");
    }
    return &this->mElements[row*this->mCols];
}

double &Matrix::operator()(int row, int col) {
    if (row >= this->mRows || row < 0 || col >= this->mCols || col < 0) {
        throw out_of_range("Out of bounds!");
    }
    return this->mElements[row * this -> mCols + col];
}

const double & Matrix::operator()(int row, int col) const {
    if (row >= this->mRows || row < 0 || col >= this->mCols || col < 0) {
        throw out_of_range("Out of bounds!");
    }
    return this->mElements[row*this->mCols+col];
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.mCols != y.mCols || x.mRows != y.mRows) {
        throw out_of_range("A ket matrix merete nem egyezik");
    }
    Matrix newMatrix(x);
    for (int i = 0; i < newMatrix.mElements.size(); ++i) {
        newMatrix.mElements[i] += y.mElements[i];
    }
    return newMatrix;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.mRows != y.mCols) {
        throw std::out_of_range("The rows of x are not equal to the cols of y.");
    }
    vector<double> mult;
    mult.resize(y.mCols * x.mRows,0);
    for (int i = 0;i < x.mRows;i++) {
        for (int j = 0;j < y.mCols;j++) {
            for (int k = 0;k < x.mCols;k++) {
                mult[i * y.mCols + j] += x.mElements[i * x.mCols + k] * y.mElements[k * y.mCols + j];
            }
        }
    }
    Matrix newMatrix(x.mRows,y.mCols);
    newMatrix.mElements = mult;
    return newMatrix;
}

std::istream & operator>>(std::istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[i*mat.mCols+j];
        }
    }
    return is;
}

std::ostream & operator<<(std::ostream &os, const Matrix &mat) {
    /*
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            os << mat.mElements[i*mat.mCols+j] << " ";
        }
        os << endl;
    }
    */
    mat.printMatrix(os);
    return os;
}
