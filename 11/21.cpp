#include <iostream>
#include <string>

using namespace std;

class MyVector2 {
public:
// Implement constructor & destructor
MyVector2() :length(0), a(NULL) { }

MyVector2(int length) : length(length), a(new double[length]) { }
MyVector2(const MyVector2& mv){
  length = mv.length;
  a = new double[length];
  for(int i = 0; i < length; ++i){
    a[i] = mv.a[i];
  }
  cout << "(copy constructor)" << endl;
}

~MyVector2(){ 
  delete[] a;
}
// Implement operators
MyVector2 &operator=(const MyVector2& mv){
  length = mv.length;
  a = new double[length];
  for(int i = 0; i < length; ++i){
    a[i] = mv.a[i];
  }
  cout << "(assignment operator)" << endl;
  return *this;
}

MyVector2 operator+(const MyVector2& b){
    MyVector2 tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] + b.a[i];
    }
    return tmp;
}
MyVector2 operator-(const MyVector2& b){
    MyVector2 tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] - b.a[i];
    }
    return tmp;
}

MyVector2 operator+(const int b){
    MyVector2 tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] + b;
    }
    return tmp;
}
MyVector2 operator-(const int b){
    MyVector2 tmp(length);
    for(int i = 0; i < length; ++i) {
        tmp.a[i] = a[i] - b;
    }
    return tmp;
}
friend std::ostream& operator<< (std::ostream& out, MyVector2& b);
friend std::istream& operator>> (std::istream& in, MyVector2& b);

// Add an additional constructor or operator if needed.
private:
  
    int length;
    double *a;
};
std::ostream& operator<< (std::ostream& out, MyVector2& b){
    for(int i = 0; i < b.length; i++) {
        out << b.a[i] << ' ';
    }
    return out;
}
std::istream& operator>> (std::istream& in, MyVector2& b){
    for(int i = 0; i < b.length; ++i) {
        in >> b.a[i];
    }
    return in;
}

int main() {
  MyVector2 *vec1 = NULL;
  MyVector2 *vec2 = NULL;
  MyVector2 *vec3 = NULL;
  string command;
  string option;
  int flag = 1;
  string what;
  string s1, op, s2;
  int len;
  

  while(true) {
    cin >> command;
    if(command == "new") {
      cin >> len;
      vec1 = new MyVector2(len);
      vec2 = new MyVector2(len);
      cout << "enter a" << endl;
      cin >> *vec1;
      cout << "enter b" << endl;
      cin >> *vec2;

    }
      
    else if(command == "set"){
      cin >> option;
      if(option == "copy"){
        flag = 1;
      }
      else if(option == "assign"){
        flag = 0;
      }
    }
      
    else if(command == "c=") {
      if(flag == 1){
      cin >> s1 >> op >> s2;

      if(op == "+") {
        if(s1 == "a" && s2 == "a") {
          MyVector2 v(*vec1 + *vec1);
          vec3 = new MyVector2(v);
        }

        else if(s1 == "a" && s2 == "b") {
          MyVector2 v(*vec1 + *vec2);
          vec3 = new MyVector2(v);
        }

        else if(s1 == "b" && s2 == "a") {
          MyVector2 v(*vec2 + *vec1);
          vec3 = new MyVector2(v);
        }
        else if(s1 == "b" && s2 == "b") {
          MyVector2 v(*vec2 + *vec2);
          vec3 = new MyVector2(v);
        }

        else if(s1 == "a" && (s2 != "a" && s2 != "b")){
          MyVector2 v(*vec1 + stoi(s2));
          vec3 = new MyVector2(v);
        }
        else if(s1 == "b" && (s2 != "a" && s2 != "b")){
          MyVector2 v(*vec2 + stoi(s2));
          vec3 = new MyVector2(v);
        }
      }

      else if(op == "-") {
        if(s1 == "a" && s2 == "a") {
          MyVector2 v(*vec1 - *vec1);
          vec3 = new MyVector2(v);
        }

        else if(s1 == "a" && s2 == "b") {
          MyVector2 v(*vec1 - *vec2);
          vec3 = new MyVector2(v);
        }

        else if(s1 == "b" && s2 == "a") {
          MyVector2 v(*vec2 - *vec1);
          vec3 = new MyVector2(v);
        }
        else if(s1 == "b" && s2 == "b") {
          MyVector2 v(*vec2 - *vec2);
          vec3 = new MyVector2(v);
        }

        else if(s1 == "a" && (s2 != "a" && s2 != "b")){
          MyVector2 v(*vec1 - stoi(s2));
          vec3 = new MyVector2(v);
        }
        else if(s1 == "b" && (s2 != "a" && s2 != "b")){
          MyVector2 v(*vec2 - stoi(s2));
          vec3 = new MyVector2(v);
        }
    }
    }
    else if(flag == 0){
      cin >> s1 >> op >> s2;

      if(op == "+") {
        if(s1 == "a" && s2 == "a") {
          vec3 = new MyVector2();
          *vec3 = *vec1 + *vec1;
        }

        else if(s1 == "a" && s2 == "b") {
          vec3 = new MyVector2();
          *vec3 = *vec1 + *vec2;
        }

        else if(s1 == "b" && s2 == "a") {
          vec3 = new MyVector2();
          *vec3 = *vec2 + *vec1;
        }
        else if(s1 == "b" && s2 == "b") {
          vec3 = new MyVector2();
          *vec3 = *vec2 + *vec2;
        }

        else if(s1 == "a" && (s2 != "a" && s2 != "b")){
          vec3 = new MyVector2();
          *vec3 = *vec1 + stoi(s2);
        }
        else if(s1 == "b" && (s2 != "a" && s2 != "b")){
          vec3 = new MyVector2();
          *vec3 = *vec2 + stoi(s2);
        }
      }

      else if(op == "-") {
        if(s1 == "a" && s2 == "a") {
          vec3 = new MyVector2();
          *vec3 = *vec1 - *vec1;
        }

        else if(s1 == "a" && s2 == "b") {
          vec3 = new MyVector2();
          *vec3 = *vec1 - *vec2;
        }

        else if(s1 == "b" && s2 == "a") {
          vec3 = new MyVector2();
          *vec3 = *vec2 - *vec1;
        }
        else if(s1 == "b" && s2 == "b") {
          vec3 = new MyVector2();
          *vec3 = *vec2 - *vec2;
        }

        else if(s1 == "a" && (s2 != "a" && s2 != "b")){
          vec3 = new MyVector2();
          *vec3 = *vec1 - stoi(s2);
        }
        else if(s1 == "b" && (s2 != "a" && s2 != "b")){
          vec3 = new MyVector2();
          *vec3 = *vec2 - stoi(s2);
        }
    }
    }
      }
      
    else if(command == "print") {
          cin >> what;
          
          if(what == "a") {
            cout << *vec1 << endl;
          }
          else if(what == "b"){
            cout << *vec2 << endl;
          }

          else if(what == "c"){
            cout << *vec3 << endl;
            }
          }
    else if(command == "quit") {
      delete vec3;
      break;
    }
  }
  return 0;
}