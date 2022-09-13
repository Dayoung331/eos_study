#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    getline(cin, str, ',');
    getline(cin, str, ',');
    getline(cin, str, ',');
    cout << str << endl;

    return 0;

    //hello:world,good,bye,를 입력했을 때 bye만 출력
}