#include <iostream>
#include <set>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

set<int> parseSet(const string& str){
  set<int> s;
  stringstream ss(str);
  ss.str(str);
  string number;
  while(ss >> number) {
    s.insert(stoi(number));
  }  
  return s;
}
void printSet(const set<int>& s){
  for (set<int>::const_iterator it = s.begin(); it != s.end(); ++it) {
    cout << " " << *it;
  }
}
set<int> getIntersection(const set<int>& set0, const set<int>& set1){
  set<int> _intersection;
  for(set<int>::iterator it0 = set0.begin(); it0 != set0.end(); it0++){
    if(set1.count(*it0) != 0){
      _intersection.insert(*it0);
    }
  }
  return _intersection;
} 

set<int> getUnion(const set<int>& set0, const set<int>& set1){
  set<int> _union;
  for(set<int>::iterator it0 = set0.begin(); it0 != set0.end(); it0++){
    _union.insert(*it0);
  }
  for(set<int>::iterator it1 = set1.begin(); it1 != set1.end(); it1++){
    if(set0.count(*it1) == 0){
      _union.insert(*it1);
    }
  }
  return _union;
}
set<int> getDifference(const set<int>& set0, const set<int>& set1){
  set<int> _difference;
  for(set<int>::iterator it0 = set0.begin(); it0 != set0.end(); it0++){
    _difference.insert(*it0);
  }
  for(set<int>::iterator it1 = set1.begin(); it1 != set1.end(); it1++){
    if(set0.count(*it1) == 1){
      _difference.erase(*it1);
    }
  }
  return _difference;
}

int main(){
  string input;
  string set1_string;
  string set2_string;
  int set1_first_index, set1_last_index;
  int set2_first_index, set2_last_index;
  int set1_len, set2_len;
  set<int> set1;
  set<int> set2;
  string _operator;
  int status=0;
    
  while(true){
    getline(cin, input);
    if(input == "0"){
      break;
    }
    set1_first_index = input.find("{");
    set1_last_index = input.find("}");
    set1_len = set1_last_index - set1_first_index - 3;
    set1_string = input.substr(set1_first_index + 2, set1_len);

    if(input.find("+") != std::string::npos){
      _operator = input.substr(input.find("+"), 1);
    }
    else if(input.find("*") != std::string::npos){
      _operator = input.substr(input.find("*"), 1);
    }
    else if(input.find("-") != std::string::npos){
      _operator = input.substr(input.find("-"), 1);
    }

    set2_first_index = input.find("{", set1_last_index+1);
    set2_last_index = input.find("}", set1_last_index+1);
    set2_len = set2_last_index - set2_first_index - 3;
    set2_string = input.substr(set2_first_index + 2, set2_len);

    set1 = parseSet(set1_string);
    set2 = parseSet(set2_string);

    if(_operator == "+"){
      cout << "{";
      printSet(getUnion(set1, set2));
      cout << " }" << endl;
    }
    else if(_operator == "*"){
      cout << "{";
      printSet(getIntersection(set1, set2));
      cout << " }" << endl;
    }
    else if(_operator == "-"){
      cout << "{";
      printSet(getDifference(set1, set2));
      cout << " }" << endl;
    }
  }
  return 0;
}