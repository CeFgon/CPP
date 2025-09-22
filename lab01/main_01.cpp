#include <iostream>
#include "functions.h"
#include "hello.h"

using namespace std;

int main() {
    //cout << "Hello, Lab_01" << endl;
    //hello();

    //1. feladat
    /*
    for (int i=0; i<=127; i++) {
        cout << i << " has " << countBits(i) << " of 1s."<<endl;
    }
    */
    //2.feladat
    /*
    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)) {
            cout<<i<<" ---> " << n <<endl;
        } else {
            cout<<"Impossible operation!" << endl;
        }
    }
    */
    //3. feladat
    /*
    double array[] = {1.5,2.3,4.5};
    int numElemofArray = 3;
    cout << "Mean: " << mean(array,numElemofArray);
    */
    //4. feladat
    /*
    double array[] = {1.5,2.3,4.5};
    int numElemofArray = 3;
    cout << "Standard Deviation: " << stddev(array,numElemofArray);
    */
    //5. feladat
    double array[] = {1.5,2.3,4.5};
    int numElemofArray = 3;
    std::pair<double, double> maxElements = max2(array, numElemofArray);
    cout << "Maximum elements(2): " << maxElements.first << ", " <<maxElements.second;
    return 0;
}
