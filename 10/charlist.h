#include <iostream>
#include <list>
#include <string>

using namespace std;

class CharList{
    public:
    CharList(const char* str);
    ~CharList();

    bool CheckPalindrome();
    list<char> GetAll();

    private:
    list<char> mystring_;
};