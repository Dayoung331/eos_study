#include <iostream>
#include <string>
#include "swap.h"

using namespace std;

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    string s1, s2;
    cin >> s1 >> s2;
    cout << "n1: " << n1 << ", n2: " << n2 << ", s1: " << s1 << ", s2: " << s2 << endl;
    swapInt(n1, n2);
    swapString(s1, s2);
    cout << "n1: " << n1 << ", n2: " << n2 << ", s1: " << s1 << ", s2: " << s2;

    return 0;
}