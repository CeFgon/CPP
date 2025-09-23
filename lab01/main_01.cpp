#include <iostream>
#include <fstream>
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
    /*
    double array[] = {1.5, 2.3, 4.5};
    int numElemofArray = 3;
    std::pair<double, double> maxElements = max2(array, numElemofArray);
    cout << "Maximum elements(2): " << maxElements.first << ", " <<maxElements.second;
    */
    //Karakterlancok
    //1.feladat
    /*
    double sum = 0;
    istringstream inputstream("./a.out 1.1 2.2 3.3 alma korte 4.4");
    string word;
    while(inputstream >> word){
        istringstream wordstream(word);
        double number;
        if( wordstream >> number ) {
            sum += number;
        }
    }
    cout<<"Sum of numeric elements: "<<sum<<endl;
    */
    //2.feladat
    /*
    string text;
    getline(cin,text);
    cout<<"Number of words: "<<countWords(text)<<endl;
    */
    //3.feladat
    /*
    string text;
    getline(cin,text);
    string temp = code(text);
    cout<<"Encoded text: "<<temp<<endl;
    */
    //4.feladat
    /*
    string text;
    getline(cin,text);
    cout<<"Capitalized: "<<capitalizeWords(text)<<endl;
    */
    //5.feladat                               ---to be made---
    /*
    string filename;
    int n;
    cin>>filename>>n;
    ifstream fin(filename);
    fin.close();
    */
    return 0;
}
