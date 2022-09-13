#include <iostream>
#include <string>

using namespace std;

int main(){
    string str = "hello world";
    cout << str << endl;

    string str1 = str + " - bye world";  //스트링끼리 더할 수 있음
    cout << str1 << endl;
    cout << str1.length() << endl;  //스트링의 길이를 반환하는 함수, 널포인터 포함
    cout << str1[0] << endl;

    str[0] = 'j';
    str.resize(4);   //크기를 재할당하는 함수
    cout << str << endl;

    return 0;
}