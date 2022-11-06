#include "headers/matrix.h"
#include <bits/stdc++.h>

using namespace std;
int main(){
    Matrix<int> a, b;
    a.read(); b.read();

    a.print();
    cout << '\n';
    b.print();
    cout << '\n';

    Matrix<int> c;
    c.matrix = a.matrix * b.matrix;
    c.pprint();
    cout << '\n';

    c.transpose();
    c.print();
    c.pprint();
    return 0;
}