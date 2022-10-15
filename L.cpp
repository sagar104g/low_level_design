/*
    Liskov Substitution
    When a child Class cannot perform the same actions as its parent Class, this can cause bugs.
    This principle aims to enforce consistency so that the parent Class or its child Class can be used in the same way without any errors.
*/
#include<vector>
#include <string>
using namespace std;


//there is no need of inheritance in below code this should not be done
class Rectangle {
    public:
       void setWidth(double w);
       void setHeight(double h);
       void getHeight();
       void getWidth();
};

class Square : public Rectangle {
    public:
       void setWidth(double w); //set both height and weidth
       void setHeight(double h); //set both height and weidth
       void getHeight();
       void getWidth();
};

