#include <iostream>
#include <string>

using namespace std;

class MyVector {
public:
// Implement constructor & destructor
MyVector() :length(0), a(NULL) { }

MyVector(int length) : length(length), a(new double[length]) { }

~MyVector(){ }
// Implement operators
MyVector operator+(const MyVector& b){
    MyVector tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] + b.a[i];
    }
    return tmp;
}
MyVector operator-(const MyVector& b){
    MyVector tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] - b.a[i];
    }
    return tmp;
}

MyVector operator+(const int b){
    MyVector tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] + b;
    }
    return tmp;
}
MyVector operator-(const int b){
    MyVector tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] - b;
    }
    return tmp;
}
friend std::ostream& operator<< (std::ostream& out, MyVector& b);
friend std::istream& operator>> (std::istream& in, MyVector& b);
double *a;

// Add an additional constructor or operator if needed.
private:
    int length;
};
std::ostream& operator<< (std::ostream& out, MyVector& b){
    for(int i = 0; i < b.length; i++) {
        out << b.a[i] << ' ';
    }
    return out;
}
std::istream& operator>> (std::istream& in, MyVector& b){
    for(int i = 0; i < b.length; ++i) {
        in >> b.a[i];
    }
    return in;
}

int main(void) {
  MyVector vec1, vec2, vec3;
  string command;
  string what;
  string s1, op, s2;
  int len;

  while(true) {
    cin >> command;

    if(command == "new") {
      cin >> len;
      vec1 = MyVector(len);
      vec2 = MyVector(len);
      vec3 = MyVector(len);
      cout << "Enter a" << endl;
      cin >> vec1;
      cout << "Enter b" << endl;
      cin >> vec2;
    }
      

    else if(command == "c=") {
      cin >> s1 >> op >> s2;

      if(op == "+") {
        if(s1 == "a" && s2 == "a") {
          vec3 = vec1 + vec1;
        }

        else if(s1 == "a" && s2 == "b") {
          vec3 = vec1 + vec2;
        }

        else if(s1 == "b" && s2 == "a") {
          vec3 = vec2 + vec1;
        }
        else if(s1 == "b" && s2 == "b") {
          vec3 = vec2 + vec2;
        }

        else if(s1 == "a" && (s2 != "a" && s2 != "b")){
          vec3 = vec1 + stoi(s2);
        }
        else if(s1 == "b" && (s2 != "a" && s2 != "b")){
          vec3 = vec2 + stoi(s2);
        }
      }

      else if(op == "-") {
        if(s1 == "a" && s2 == "a") {
          vec3 = vec1 - vec1;
        }

        else if(s1 == "a" && s2 == "b") {
          vec3 = vec1 - vec2;
        }

        else if(s1 == "b" && s2 == "a") {
          vec3 = vec2 - vec1;
        }
        else if(s1 == "b" && s2 == "b") {
          vec3 = vec2 - vec2;
        }

        else if(s1 == "a" && (s2 != "a" && s2 != "b")){
          vec3 = vec1 - stoi(s2);
        }
        else if(s1 == "b" && (s2 != "a" && s2 != "b")){
          vec3 = vec2 - stoi(s2);
        }
    }
    }
    else if(command == "print") {
          cin >> what;
          
          if(what == "a") {
            cout << vec1 << endl;
          }
          else if(what == "b"){
            cout << vec2 << endl;
          }

          else if(what == "c"){
            cout << vec3 << endl;
          }
      }
    else if(command == "quit") {
      break;
    }
  }
  return 0;
}