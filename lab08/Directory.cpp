//
// Created by cefgo on 12/11/2025.
//

#include "Directory.h"

Directory::Directory(const string &name) : FileSystemItem(){
    this->name = name;
    this->size = 0;
}

Directory::Directory(const Directory &other) {
    this->name = other.name;
    this->size = other.size;
    for (auto a:other.children) {
        this->children.push_back(a->clone());
    }
}

Directory & Directory::operator=(const Directory &other) {
    if (this!=&other) {
        this->name = other.name;
        this->size = other.size;
        for (auto a:other.children) {
            this->children.push_back(a->clone());
        }
    }
    return *this;
}

Directory::~Directory() {
    for (auto i : children) {
        delete i;
    }
    children.clear();
}

void Directory::add(FileSystemItem *item) {
    this->children.push_back(item);
    this->size += item->getSize();
}

void Directory::remove(const string& name) {
    auto it = find_if(this->children.begin(),this->children.end(),[&name](FileSystemItem* i) {
        return i->getName() == name;
    });
    if (it == this->children.end()) {
        throw out_of_range("Nincs benne");
    }
    this->children.erase(it);
    delete *it;
}

FileSystemItem * Directory::find(const string &name) {
    auto it = find_if(this->children.begin(),this->children.end(),[&name](FileSystemItem* i) {
        return i->getName() == name;
    });
    if (it ==this->children.end()) {
        throw out_of_range("Nincs benne");
    }
    return *it;
}

long Directory::getSize() const {
    int sum;
    for (auto i : children) {
        sum += i->getSize();
    }
    return sum;
}

string Directory::getName() const {
    return this->name;
}

void Directory::display(int depth) const {
    cout << this; //ez nem jo
    if (depth == 0) {
        return;
    }
    for (auto i : children) {
        cout << *i;
        i->display(depth-1);
    }
}

Directory & Directory::operator+=(FileSystemItem &what) {
    this->children.push_back(&what);
    return *this;
}

Directory & Directory::operator-=(FileSystemItem &what) {
    auto it = find_if(this->children.begin(),this->children.end(),[&what](FileSystemItem* i) {
        return i->getName() == what.getName();
    });
    if (it == this->children.end()) {
        throw out_of_range("Nincs benne");
    }
    this->children.erase(it);
    delete *it;
    return *this;
}

FileSystemItem * Directory::clone() const {
    return new Directory(*this);
}

ostream &operator<<(ostream &os, FileSystemItem &what) {
    os << what.name << " (" << what.size << ")"<<endl;
    return os;
}
