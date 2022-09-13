#include <iostream>

using namespace std;

int main(){
    string line;
    cout << "write a line" << endl;
    while (getline(cin, line)){
        cout << line << "---" << endl;
    }
//그냥 cout << string 으로 하면 공백으로 구분되지만 getline을 써주면 널포인터가 나오기 전까지 공백으로 구분되지 않고 출력할 수 있음.
    return 0;
}