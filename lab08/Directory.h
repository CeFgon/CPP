//
// Created by cefgo on 12/11/2025.
//

#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <vector>
#include <algorithm>
#include "FileSystemItem.h"

class Directory : public FileSystemItem{
    vector<FileSystemItem*> children;
public:
    Directory(const string& name);
    Directory(const Directory& other);
    Directory& operator =(const Directory& other);
    ~Directory();
    void add(FileSystemItem* item);
    void remove(const string& name);
    FileSystemItem* find(const string& name);
    long getSize() const override;
    virtual string getName() const override;
    void display(int depth) const override;
    Directory& operator +=(FileSystemItem& what);
    Directory& operator -=(FileSystemItem& what);
    FileSystemItem* clone() const override;
    friend ostream& operator <<(ostream &os, FileSystemItem &what);
};

#endif //DIRECTORY_H
