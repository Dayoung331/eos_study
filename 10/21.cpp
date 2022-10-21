#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(){
    list<int> lt;
    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);

    list<int>::iterator iter;
    for(iter = lt.begin(); iter!= lt.end(); iter++){
        cout << *iter <<  " ";
    }
    cout << endl;

    iter = lt.begin();
    iter++; iter++;
    cout << *iter << endl;

    list<int>::iterator iter2 = lt.erase(iter);
    cout << *iter2 << endl;

    lt.remove(10);
    for(iter = lt.begin(); iter != lt.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}