//
// Created by cefgo on 12/11/2025.
//

#include "File.h"

File::File(const string& name, long size) : FileSystemItem() {
    this->size = size;
    this->name = name;
}

File::File(const File& other) : FileSystemItem(){
    this->name = other.name;
    this->size = other.size;
}

long File::getSize() const {
    return this->size;
}

void File::display(int depth) const{
    cout << this->name << " (" << this->size << ")"<<endl;
}

string File::getName() const {
    return this->name;
}

FileSystemItem* File::clone() const {
    File* copy = new File(*this);
    return copy;
}
