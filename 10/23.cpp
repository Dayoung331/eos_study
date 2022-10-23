#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    cout <<  "size: " <<  q.size() << endl;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "size: " << q.size() << endl;
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() <<  endl <<  endl;

    while(!q.empty()){
        cout <<  q.front() <<  endl;
        q.pop();
    }
    
    return 0;
}