#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    //std::cout << "Hello, Lab_04" << std::endl;
    double d1[]={1,2,3,4,5};
    double d2[]={10,12,53,44,95};
    Polynomial *p1 = new Polynomial(4,d1);
    Polynomial *p2 = new Polynomial(4,d2);
    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << *p1 + *p2 << endl;
    cout << *p1 - *p2 << endl;
    cout << -(*p1) << endl;
    return 0;
}