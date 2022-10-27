#include <iostream>

using namespace std;

int main(){

    string one("Lottery Winner!");
    cout << one << endl;

    string two(20, '$');
    cout << two << endl;

    string three(one);
    cout << three << endl;
    one += "Ooops!";
    cout << one << endl;

    return 0;
}