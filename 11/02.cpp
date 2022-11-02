#include <iostream>
using namespace std;

class Circle{
    protected:
    int x, y;
    double radius;

    public:
    Circle(){
        cout << "Circle: no parameter" << endl;
    }
    Circle(int px, int py, double pradius){
        cout << "Circle: with parameters" << endl;
        x=px; y=py; radius=pradius;
    }
    double getArea(){
        return 3.14*radius*radius;
    }
};

class Sphere: public Circle{
    private: int z;

    public:
    Sphere(int px, int py, double pradius, int pz){
        cout << "Sphere" << endl;
        x=px; y=py; radius=pradius; z=pz;
    }
    double getVolumn(){
        return 4.0/3*3*radius*radius*radius;
    }
};


int main(){
    Circle c(2, 3, 4.0);
    cout << c.getArea() << endl;
    Sphere s(2, 3, 4.0, 5);
    cout << s.getVolumn() << endl;

    return 0;
}