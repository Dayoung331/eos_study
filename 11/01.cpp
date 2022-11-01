#include <iostream>
using namespace std;

class Parent {
    public:
    Parent(){
        cout << "Parent";
    }
    ~Parent(){
        cout << "~Parent";
    }
};

class Child : public Parent{
    public:
    Child() {
        cout << "Child";
    }
    ~Child(){
        cout << "~Child";
    }
};

class Test : public Child{
    public:
    Test(){
        cout << "Test";
    }
    ~Test(){
        cout << "~Test";
    }
};


int main(){
    {
        Child child;
        cout <<  endl;
    }
    cout <<  endl;
    {
        Test test;
        cout << endl;
    }
    cout <<  endl;

    return 0;
}