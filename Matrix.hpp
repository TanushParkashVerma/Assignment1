//
// Created by tanus on 2019-10-11.
//

#ifndef ASSIGNMENT1_MATRIX_HPP
#define ASSIGNMENT1_MATRIX_HPP

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<double> > matrix; // 2-D vector to store matrix data
public:
    // constructors
    // creates a matrix of 1 X 1
    Matrix();

    // creates a matrix of n * n
    Matrix(int n);

    // creates a matrix with r rows and c columns
    Matrix(int r, int c);

    // create a matrix with given values
    Matrix(vector<double> &v);

    // destructor
    ~Matrix();

    // set given value at given position in matrix
    void setValue(int row, int col, double value);

    // returns a value from given location
    double getValue(int row, int col);

    // sets all values in the matrix to 0.0
    void clear();

    // return true if 2 matrix are equal otherwise return false
    bool operator==(const Matrix &mt);

    // return true if 2 matrix are not equal otherwise return false
    bool operator!=(const Matrix &mt);

    // increase each element in vector by 1.0
    Matrix &operator++(int);

    // decrease each element in vector by 1.0
    Matrix &operator--(int);

    // add two matrices and return resulting matrix
    Matrix &operator+(const Matrix &mt);

    // substract second matrix from first matrix and return resulting matrix
    Matrix &operator-(const Matrix &mt);

    // add second matrix to first one
    Matrix &operator+=(const Matrix &mt);

    // substract second matrix from first one
    Matrix &operator-=(const Matrix &mt);

    // multyply first matrix with seecond matrix and return resulting matrix
    Matrix &operator*(const Matrix &mt);

    // multyply and modify first matrix with seecond matrix
    Matrix &operator*=(const Matrix &mt);

    // creates a copy of given matrix and assign to the matrix
    Matrix &operator=(const Matrix &mt);

    friend ostream &operator<<(ostream &os, const Matrix &mt);
};


#endif //ASSIGNMENT1_MATRIX_HPP
