#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int* numArr = new int[N];
  for(int i=0; i<N; i++){
    cin >> numArr[i];
    }
  int target, count;
  count = 0;
  cin >> target;
 
  for(int i=0; i<N; i++){
    if(target == numArr[i]){
      count += 1;
    }
  }
  cout << "target value: " << target << endl;
  cout << "target count: " << count;
  delete[] numArr;
 
  return 0;
}
