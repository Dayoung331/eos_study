#include <iostream>
#include <list>
#include <string>
#include <cstring>

#include "charlist.h"

using namespace std;

CharList::CharList(const char* str){
    for(int i=0; i<strlen(str); i++){
        mystring_.push_back(str[i]);
    }
}
CharList::~CharList(){
    mystring_.clear();
}

bool CharList::CheckPalindrome(){
    list<char>::iterator iter = mystring_.begin();
    char * string = new char[mystring_.size()+1];
    for(int i=0; i<mystring_.size(); i++){
        string[i] = *iter;
        iter++;
    }
    for(int i=0; i<mystring_.size(); i++){
        if(string[i] != string[mystring_.size() - i -1]){
            return false;
        }
    }
    delete[] string;
    return true;
}

list<char> CharList::GetAll(){
    return mystring_;
}