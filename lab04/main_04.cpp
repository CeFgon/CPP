#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    //std::cout << "Hello, Lab_04" << std::endl;
    double d1[]={1,2,3,4,5};
    double d2[]={10,12,53,44,95};

    const Polynomial p1(4, d1), p2(4, d2);
    cout << p1;
    cout << p1.derivative();
    cout << p1.evaluate(1);

    cout << p1 + p2;
    cout << p1 - p2;
    cout << p1 * p2;
    return 0;
}