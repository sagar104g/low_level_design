/*
    Interface Segregation
    Clients should not be forced to depend on methods that they do not use.
    This principle aims at splitting a set of actions into smaller sets so that a Class executes ONLY the set of actions it requires.
*/
#include<vector>
#include <string>
using namespace std;


//there is no need of groom in Tiger below code this should not be done
class Animal {
    public:
       void feed();
       void groom();
};

class Dog : public Animal {
    public:
       void feed();
       void groom();
};

class Tiger : public Animal {
    public:
       void feed();
       void groom(); // Dummy implementation - to keep compiler happy
};


//this is good here we are not forcing groom to tiger
class Animal {
    public:
       void feed();
};

class Pet : public Animal {
    public:
       void groom();
};

class Dog : public Animal, public Pet {
    public:
       void feed();
       void groom();
};

class Tiger : public Animal {
    public:
       void feed();
};