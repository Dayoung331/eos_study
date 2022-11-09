#include <iostream>
#include <string>

using namespace std;

class Animal{
    public:
    virtual string talk()= 0;
};
class Cat : public Animal{
    public:
    virtual string talk(){ 
        return "Meow!";
    }
};
class Dog : public Animal{
    public:
    virtual string talk(){ 
        return "Woof!";
    }
};
void letsHear(Animal& animal){ 
    cout<< animal.talk()<< endl; 
}

int main(){
    Cat cat;
    Dog dog;
    letsHear(cat);
    letsHear(dog);
    return 0;
}