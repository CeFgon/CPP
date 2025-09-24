#include <iostream>
#include "point.h"
#include "utils.h"

using namespace std;
int main(int argc, char** argv) {
    Point p1(2,3);
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
    Point p2(100, 200);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    //pp1 -> print;
    cout<<distance(*pp1,*pp2)<<endl;
    delete pp1;
    delete pp2;
    Point p3(1,1);
    Point p4(1,2);
    Point p5(2,1);
    Point p6(2,2);
    //cout << isSquare(p3,p4,p5,p6)<<endl;
    //testIsSquare("be1.txt");
    Point* array = createArray(100);
    printArray(array,100);
    pair<Point,Point> closest = closestPoints(array,100);
    cout<<"Closest points"<<endl;
    closest.first.print();
    closest.second.print();
    pair<Point,Point> farthest = farthestPoints(array,100);
    cout<<"Farthest points"<<endl;
    farthest.first.print();
    farthest.second.print();
    cout<<"After sort:"<<endl;
    sortPoints(array, 100);
    printArray(array,100);
    return 0;
}
