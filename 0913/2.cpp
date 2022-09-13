#include <iostream>

using namespace std;

int main(){
    string line;
    cout << "write a line" << endl;
    while(cin >> line && line != "q"){
        cout << line << "---" <<endl; //스페이스로 구분해서 출력함 ---, endl 하나씩 돌고 출력함.
    }
    return 0;
}