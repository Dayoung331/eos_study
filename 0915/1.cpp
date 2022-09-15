#include <iostream>
#include <string>

using namespace std;

int main() {
  string line1, line2;
  cin >> line1;
  cin >> line2;
  string str = line1 + line2;
  cout << str << endl;
  cout << str[0] << endl;
  cout << str[str.length()-1] << endl;

  return 0;
 
}