//
// Created by tanus on 2019-10-11.
//

#include "Matrix.hpp"

Matrix::Matrix() {
    // created a matrix of 1X1 filled with 0.0
    // created a vactor of row
    vector<double> row;
    // added elemnt to the row vector
    row.push_back(0.0);
    // added row vector to the matrix
    matrix.push_back(row);

}

Matrix::Matrix(int n) {
    // checked if n is negative or 0
    if (n > 0) {
        // created a vector of size n
        for (int i = 0; i < n; i++) {
            vector<double> row;
            // filled vector with 0.0
            for (int j = 0; j < n; j++) {
                row.push_back(0.0);
            }
            // added each row to matrix
            matrix.push_back(row);
        }
    } else {
        // throw an exception
        throw -1;
    }

}

Matrix::Matrix(int r, int c) {
    // checked if r or c is negative or 0
    if (r > 0 && c > 0) {
        // created matrix of r row
        for (int i = 0; i < r; i++) {
            // each row contains c elements
            vector<double> row;
            for (int j = 0; j < c; j++) {
                // filled each row with 0.0
                row.push_back(0.0);
            }
            // added each row to thee matrix
            matrix.push_back(row);
        }
    } else {
        // throw an exception
        throw -1;
    }

}

Matrix::Matrix(vector<double> &v) {
    // checked if given vector is of perfect square
    // get size of vector
    int size = v.size();
    int row = -1;
    // get sqrt of size if its perfect square
    for (int i = 1; i <= size; i++) {
        if ((size % i == 0) && (size / i == i)) {
            row = i;
            break;
        }
    }
    // checked if row is -1
    if (row == -1) {
        // thow exception
        throw -1;
    } else {
        for (int i = 0; i < row; i++) {
            // get each row
            vector<double> r;
            for (int j = 0; j < row; j++) {
                r.push_back(v.at(i * row + j));
            }
            // added each row to the matrix
            matrix.push_back(r);
        }
    }

}

Matrix::~Matrix() {
    // delete matrix
    for (int i = 0; i < matrix.size(); i++) {
        matrix.at(i).clear();
    }
    matrix.clear();

}

void Matrix::setValue(int row, int col, double value) {
    // checked for vaild location
    if (row <= 0 || row > matrix.size()) {
        // throw exception
        throw -1;
    } else if (col <= 0 || col > matrix.at(0).size()) {
        // throw exception
        throw -1;
    } else {
        // set new value to the location
        matrix.at(row - 1).at(col - 1) = value;
    }

}

double Matrix::getValue(int row, int col) {
    // checked for vaild location
    if (row <= 0 || row > matrix.size()) {
        // throw exception
        throw -1;
    } else if (col <= 0 || col > matrix.at(0).size()) {
        // throw exception
        throw -1;
    } else {
        // return value from the location
        return matrix.at(row - 1).at(col - 1);
    }
}

void Matrix::clear() {
    // reset all elements in matrix to 0.0
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.at(i).size(); j++) {
            matrix.at(i).at(j) = 0.0;
        }
    }

}

bool Matrix::operator==(const Matrix &mt) {
    // checked for row size
    if (this->matrix.size() != mt.matrix.size()) {
        return false;
    }
        // checked for column size
    else if (this->matrix.at(0).size() != mt.matrix.at(0).size()) {
        return false;
    } else {
        // checked for each elements
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.at(i).size(); j++) {
                if (this->matrix.at(i).at(j) != mt.matrix.at(i).at(j)) {
                    return false;
                }
            }
        }
        return true;
    }
}

bool Matrix::operator!=(const Matrix &mt) {
    // checked for row size
    if (this->matrix.size() != mt.matrix.size()) {
        return true;
    }
        // checked for column size
    else if (this->matrix.at(0).size() != mt.matrix.at(0).size()) {
        return true;
    } else {
        // checked for each elements
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.at(i).size(); j++) {
                if (this->matrix.at(i).at(j) != mt.matrix.at(i).at(j)) {
                    return true;
                }
            }
        }
        return false;
    }
}

Matrix &Matrix::operator++(int) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.at(i).size(); j++) {
            // increase each value by 1.0
            matrix.at(i).at(j) = matrix.at(i).at(j) + 1.0;
        }
    }
    return *this;
}

Matrix &Matrix::operator--(int) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.at(i).size(); j++) {
            // decrease each value by 1.0
            matrix.at(i).at(j) = matrix.at(i).at(j) - 1.0;
        }
    }
    return *this;
}

Matrix &Matrix::operator+(const Matrix &mt) {
    // created a new matrix
    Matrix *m = new Matrix();
    m->matrix.clear();
    for (int i = 0; i < matrix.size(); i++) {
        // make each row
        vector<double> row;
        for (int j = 0; j < matrix.at(i).size(); j++) {
            double sum = matrix.at(i).at(j) + mt.matrix.at(i).at(j);
            row.push_back(sum);
        }
        // added each row to martix
        m->matrix.push_back(row);
    }
    return *m;
}

Matrix &Matrix::operator-(const Matrix &mt) {
    // created a new matrix
    Matrix *m = new Matrix();
    m->matrix.clear();
    for (int i = 0; i < matrix.size(); i++) {
        // make each row
        vector<double> row;
        for (int j = 0; j < matrix.at(i).size(); j++) {
            double sub = matrix.at(i).at(j) - mt.matrix.at(i).at(j);
            row.push_back(sub);
        }
        // added each row to martix
        m->matrix.push_back(row);
    }
    return *m;
}

Matrix &Matrix::operator+=(const Matrix &mt) {
    for (int i = 0; i < matrix.size(); i++) {
        // make each row
        vector<double> row;
        for (int j = 0; j < matrix.at(i).size(); j++) {
            matrix.at(i).at(j) = matrix.at(i).at(j) + mt.matrix.at(i).at(j);
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &mt) {
    for (int i = 0; i < matrix.size(); i++) {
        // make each row
        vector<double> row;
        for (int j = 0; j < matrix.at(i).size(); j++) {
            matrix.at(i).at(j) = matrix.at(i).at(j) - mt.matrix.at(i).at(j);
        }
    }
    return *this;
}

Matrix &Matrix::operator*(const Matrix &mt) {
    // multiplication is done by dot product
    // created a empty matrix
    Matrix *m = new Matrix();
    m->matrix.clear();
    for (int i = 0; i < matrix.size(); i++) {
        // build each row
        vector<double> row;
        for (int j = 0; j < mt.matrix.at(i).size(); j++) {
            // multiply first matrix's row with second matrix's column
            // added the total sum
            double sum = 0.0;
            for (int k = 0; k < matrix.at(i).size(); k++) {
                sum = sum + (matrix.at(i).at(k) * mt.matrix.at(k).at(j));
            }
            // added sum to the row
            row.push_back(sum);
        }
        // added each row to martix
        m->matrix.push_back(row);
    }
    return *m;
}

Matrix &Matrix::operator*=(const Matrix &mt) {
    // multiplication is done by dot product
    // created a empty matrix
    Matrix *m = new Matrix();
    m->matrix.clear();
    for (int i = 0; i < matrix.size(); i++) {
        // make each row
        vector<double> row;
        for (int j = 0; j < mt.matrix.at(i).size(); j++) {
            // multiply first matrix's row with second matrix's column
            // added the total sum
            double sum = 0.0;
            for (int k = 0; k < matrix.at(i).size(); k++) {
                sum = sum + (matrix.at(i).at(k) * mt.matrix.at(k).at(j));
            }
            // added sum to the row
            row.push_back(sum);
        }
        // added each row to martix
        m->matrix.push_back(row);
    }
    // reassign new matrix to this
    this->matrix.clear();
    this->matrix = m->matrix;
    return *m;
}

Matrix &Matrix::operator=(const Matrix &mt) {
    // clear current matrix
    matrix.clear();
    // copy and assign given matrix
    for (int i = 0; i < mt.matrix.size(); i++) {
        vector<double> row; // build each row
        for (int j = 0; j < mt.matrix.at(i).size(); j++) {
            row.push_back(mt.matrix.at(i).at(j)); // copy each element
        }
        // added each row to the current matrix
        matrix.push_back(row);
    }
    return *this;
}

ostream &operator<<(ostream &os, const Matrix &mt) {
    // get number of rows
    int rows = mt.matrix.size();
    // output each row to stream
    for (int i = 0; i < rows; i++) {
        os << "| ";
        // output each element of row
        for (int j = 0; j < mt.matrix.at(i).size(); j++) {
            os << mt.matrix.at(i).at(j) << " ";
        }
        os << "|" << endl;
    }
    return os;
}
