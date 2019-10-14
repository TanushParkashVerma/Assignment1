#include <iostream>

#include "Matrix.hpp"
#include "pagerank.hpp"

int main() {
    // print each step

    cout << "Testing default constructor:" << endl;
    Matrix *m1 = new Matrix();
    cout << *m1;
    cout << "Testing destructor:" << endl;
    delete m1;
    cout << "Testing Matrix(3):" << endl;
    Matrix m2(3);
    cout << m2;
    cout << "Testing Matrix(3,4):" << endl;
    Matrix m3(3, 4);
    cout << m3;
    vector<double> v;
    v.push_back(1.5);
    v.push_back(2.7);
    v.push_back(3.1);
    v.push_back(1.4);
    cout << "Testing coonstructor with vector parameter:" << endl;
    Matrix m4(v);
    cout << m4;
    cout << "getValue(1,2) at matrix 4 returns: " << m4.getValue(1, 2) << endl;
    cout << "Setting value 4.6 at 1st row and 2nd col of matrix 2:" << endl;
    m2.setValue(1, 2, 4.6);
    cout << m2;
    cout << "creating matrix 5 with assignment operaton on matrix 4:" << endl;
    Matrix *m5 = new Matrix();
    *m5 = m4;
    cout << "matrix 5: " << endl;
    cout << *m5;
    cout << "Testing == " << endl;
    if (m4 == *m5) {
        cout << "m4 and m5 are equal" << endl;
    } else {
        cout << "m4 and m5 are not equal" << endl;
    }
    cout << "Testing ++ operator on matrix 4:" << endl;
    m4++;
    cout << m4;
    cout << "Testing != " << endl;
    if (m4 != *m5) {
        cout << "m4 and m5 are not equal" << endl;
    } else {
        cout << "m4 and m5 are equal" << endl;
    }
    cout << "Adding matrix 4 and 5 to make matrix 6:" << endl;
    Matrix m6 = m4 + *m5;
    cout << m6;
    cout << "Adding matrix 4 to 6: " << endl;
    m6 += m4;
    cout << m6;
    cout << "Testing -- operator on matrix 4:" << endl;
    m4--;
    cout << m4;
    cout << "Substracting matrix 4 from 6:" << endl;
    m6 -= m4;
    cout << m6;
    cout << "making matrix 7 by substracting matrix 4 from 6:" << endl;
    Matrix m7 = m6 - m4;
    cout << m7;
    cout << "matrix 4: " << endl;
    cout << m4;
    cout << "Multiplication of m7 and m4:" << endl;
    m7 *= m4;
    cout << m7;
    cout << "Creating matrix with 2 row and 1 colum:" << endl;
    Matrix m9(2, 1);
    m9.setValue(1, 1, 2);
    m9.setValue(2, 1, 5);
    cout << m9;
    cout << "Multilpication of matrix 4 and 9:" << endl;
    Matrix m10 = m4 * m9;
    cout << m10;
    cout << "Testing clear on matrix 7:" << endl;
    m7.clear();
    cout << m7 << endl;

    return 0;
}