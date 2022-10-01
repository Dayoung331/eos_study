#include <iostream>
#include <string>
#include "swap.h"

using namespace std;

void swapString(string& s1, string& s2){
    string s = s1;
    s1 = s2;
    s2 =s;
}