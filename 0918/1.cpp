#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int* pa = &a;
    *pa = 20;
    cout << a << " " << *pa << endl;

    int b = 10;
    int& rb = b;
    rb = 20;
    cout << b << " " << rb << endl;

    return 0;
}