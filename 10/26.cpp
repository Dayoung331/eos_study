#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v;
    int input;
    cin >> input;
    while(input!=0){
        v.push_back(input);
        cin >> input;
    }
    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }

    return 0;
}