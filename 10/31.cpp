#include <iostream>
#include <string>
using namespace std;

int main(){
    string str = "We think in generalities, but we live in details.";

    string str2 = str.substr(12, 12);
    size_t pos = str.find("live");
    string str3 = str.substr(pos);

    cout << str2 << ' ' << str3 << endl;

    return 0;
}