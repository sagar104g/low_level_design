/*
    Dependency Inversion
    - High-level modules should not depend on low-level modules. Both should depend on the abstraction.
    - Abstractions should not depend on details. Details should depend on abstractions.
    This principle aims at reducing the dependency of a high-level Class on the low-level Class by introducing an interface.
*/
#include<vector>
#include <string>
using namespace std;


//there is wrong we have to change this in future is new requirement came
enum outputDevice{printer, disk}

void copy1(outputDevice dev) {

    int ch;
    while((ch = ReadKeyboard()) != EOF) {
       if (dev == printer) {
            writePrinter(c);
        } else {
            writeDisk(c);
        }
    }
}

//this is good copy method can handle any reader and writer here
class Reader {
    public:
       virtual char read() = 0;
};

class Writer {
    public:
       virtual char write(char ch) = 0;
};

void copy(Reader *r, Writer *w) {

    char ch;
    while((ch == r->read()) != EOF) {
        w->write(ch);
    }
}