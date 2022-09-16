#include <iostream>
#include <string>

using namespace std;

namespace first_space {
  void print(){
    cout<< "Print from first space" << endl;
  }
}

namespace second_space {
  void print() {
    cout<< "Print from second space" << endl;
  }
}


int main() {
  int num;
    cin >> num;
    if(num == 1){
      first_space::print();
    }
    else{
      second_space::print();
    }
 

  return 0;
 
}