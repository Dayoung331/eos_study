#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int* numArr = new int[n];
  for(int i=0; i<n; i++){
    numArr[i] = i;
    }
  for(int i=0; i<n; i++){
    cout << numArr[i] << " ";
    }
  delete[] numArr;
 
  return 0;
}