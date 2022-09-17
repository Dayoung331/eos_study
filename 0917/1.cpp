#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;   // allocate one instance
    int* num = new int;   // allocate an array
    int* numArr = new int[n];
    *num = n;
    for(int i=0; i<n; i++){
        numArr[i] = i;
    }
    cout << *num << endl;
    for(int i=0; i<n; i++){
    cout << numArr[i] << " ";
    cout << endl;
    }

    delete num;   // deallocate the instance
    delete[] numArr;   // deallocate the array

    return 0;
}