//
// Created by cefgo on 12/11/2025.
//

#ifndef FILESYSTEMITEM_H
#define FILESYSTEMITEM_H

#include <iostream>
#include <string>

using namespace std;

class FileSystemItem{
protected:
    string name;
    long size;
public:
    virtual string getName() const = 0;
    virtual long getSize() const = 0;
    virtual void display(int depth = 0) const = 0;
    virtual FileSystemItem* clone() const = 0;
    friend ostream& operator <<(ostream &os, FileSystemItem &what);
    friend bool operator <(FileSystemItem& i1, FileSystemItem& i2);
};

#endif //FILESYSTEMITEM_H
