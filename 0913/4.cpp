#include <iostream>

using namespace std;

int main(){
    string line;
    cout << "write a line" << endl;
    while (getline(cin, line, ':')) 
    // 입력 스트링에서 문자를 읽다가 ':'가 나오면 ':'를 버리고 읽기를 종료함.
    {
        cout << line << "---" <<endl;
    }

    return 0;
}