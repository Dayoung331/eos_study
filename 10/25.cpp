#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> s;
    for(int i=0; i<10; ++i){
        s.insert(i*10);
    }
    for(set<int>::const_iterator it = s.begin(); it != s.end(); ++it){
        cout << " " << *it;
    }
    cout << s.size();
    cout << s.empty();

    return 0;
}