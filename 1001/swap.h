#pragma once

using namespace std;

inline void swapInt(int &n1, int& n2){
    int n = n1;
    n1 = n2;
    n2 = n;
}

void swapString(string& s1, string& s2);