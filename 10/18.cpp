#include <iostream>
#include <map>
using namespace std;

int main (){
    string s = "0123456789";
    size_t pos = s.find("345");
    string s2 = s.substr(pos,5);
    cout << s2 << endl;
}