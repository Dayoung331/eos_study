#include <iostream>
#include <string>

using namespace std;

template <typename T>

void myswap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main(void) {
    int num1, num2;
    double dbl1, dbl2;
    string str1, str2;

    cin >> num1 >> num2;
    myswap(num1, num2);
    cout << "After calling myswap(): " << num1 << ' ' << num2 << endl;

    cin >> dbl1 >> dbl2;
    myswap(dbl1, dbl2);
    cout << "After calling myswap(): " << dbl1 << ' ' << dbl2 << endl;

    cin >> str1 >> str2;
    myswap(str1, str2);
    cout << "After calling myswap(): " << str1 << ' ' << str2 << endl;

    return 0;
}

