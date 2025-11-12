//
// Created by cefgo on 12/11/2025.
//

#ifndef FILE_H
#define FILE_H
#include "FileSystemItem.h"

class File : public FileSystemItem {
public:
    File(const string& name, long size);
    File(const File& other);
    long getSize() const override;
    void display(int depth) const override;
    virtual string getName() const override;
    FileSystemItem* clone() const override;
};

#endif //FILE_H
