#include <iostream>
#include <list>
#include <string>
#include <cstring>

#include "charlist.h"

using namespace std;

int main(){
    char input[1000];
    while(true){
        cin >> input;
        char * str = new char[strlen(input+1)];
        strcpy(str, input);
        if(strcmp(str, "quit") == 0){
            break;
        }
        else{
            CharList charlist(str);
            cout << boolalpha << charlist.CheckPalindrome() << endl;
        }
        delete[] str;
    }
    return 0;
}