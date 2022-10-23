#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, double> m;
    for(int i=0; i<4; i++){
        m.insert(make_pair("string"+to_string(i), 0.5*i));
    }
    for(map<string, double>::iterator it = m.begin(); it!= m.end(); ++it){
        cout << " " << it->first << "," << it->second << endl;
    }

    m.insert(make_pair("apple", 10));
    m["orange"] = 3.14;
    m["string0"] = 111;

    for(map<string, double>::iterator it=m.begin(); it!= m.end(); ++it){
        cout << " " << it->first << "," << it->second << endl;
    }

    map<string, double>::iterator it;
    it = m.find("apple");

    cout << "output " << it->first << " " << (*it).second << endl;
    m.clear();

    return 0;
}