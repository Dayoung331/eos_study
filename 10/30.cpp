#include <iostream>
#include <string>
using namespace std;

int main(){
    string str("There are two needles in this haystack with needles.");
    string str2("needle");
    size_t found;

    if((found = str.find(str2)) != string::npos){
        cout << "firt 'needle found at: " << int(found) << endl;
    }
    str.replace(str.find(str2), str2.length(), "preposition");
    cout << str << endl;

    return 0;
}