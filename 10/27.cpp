#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    const int a = 10, b = 15;
    int minv = min(a, b);
    int maxv = max(a, b);
    cout << minv << " " << maxv << endl;

    vector<int> v(10);
    for(int i=0; i<v.size(); ++i){
        v[i] = 2*i;
    }
    vector<int>::iterator it;
    it = min_element(v.begin(), v.end());

    random_shuffle(v.begin(), v.end());

    for(int i=0; i<v.size(); ++i){
        cout << " " << v[i];
    }
    cout << endl;

    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); ++i){
        cout << " " << v[i];
    }
    cout << endl;

    return 0;
}