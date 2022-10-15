/*
    Open/Closed Principle (OCP)
    Classes should be open for extension, but closed for modification
*/
#include<vector>
#include <string>
using namespace std;


//this is wrong way as we have to modifie Area function if we need to add square area calculation
class ShapeWrong {
    public:
        string type;
        string Area(vector<ShapeWrong> shapes) {
        double area = 0;
        for(int i = 0; i < shapes.size(); i++) {
            if ("rectangle" == shapes[i].type) {
                return "calculate rectangle area";
            } else if ("circle" == shapes[i].type) {
                return "calculate circle area";
            }
        }
        };
};

//correct way now we can add square without impacting existing code

class ShapeRight {
    public:
        virtual string Area(vector<ShapeRight> shapes) = 0;
};

class Rectangle {
    public:
        string Area(vector<ShapeRight> shapes) {
            return "calculate rectangle area";
        };
};

class Circle {
    public:
        string Area(vector<ShapeRight> shapes) {
            return "calculate Circle area";
        };
};