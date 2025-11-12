#include <iostream>
#include "Directory.h"
#include "File.h"

//nem jo a kiiratas+meg probably sok minden

int main() {
    //std::cout << "Hello, Lab_08" << std::endl;
    Directory root("root");

    File document("document",100);

    root += document;
    //cout << root;
    root.display(1);
    return 0;
}