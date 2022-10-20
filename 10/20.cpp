#include <iostream>
#include <list>

using namespace std;

void printList(list<int> intV){

    list<int>::iterator iter;
    for(iter = intV.begin(); iter != intV.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
}

int main(){
    list<int> intL(5);
    list<int>::iterator iter = intL.begin();
    for(int i=0; i<5; i++){
        *iter = i;
        iter++;
    }
    printList(intL);
    iter = intL.begin();
    iter++;
    iter = intL.insert(iter, 100);
    printList(intL);

    iter++; iter++;
    cout << *iter << endl;
    intL.erase(iter);
    printList(intL);

    return 0;
}