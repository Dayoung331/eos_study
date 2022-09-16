#include <iostream>
#include <string>

using namespace std;

int add(int a, int b){
  return a+b;
}

string add(string a, string b){
  string added = a + '-' + b;
  return added;
}

float add(float a, float b = 0.9){
  return a+b;
}

int main() {
  int a, b;
  string c, d;
  float e;
  cin >>a>>b>>c>>d>>e;
  cout<<add(a, b)<<endl;
  cout<<add(c,d)<<endl;
  cout<<add(e);

  return 0;
 
}