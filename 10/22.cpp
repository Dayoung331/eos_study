#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    stack<int> st;
    
    st.push(10);
    st.push(20);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();

    if(st.empty()){
        cout << "no data in the stack" <<  endl;
    }

    return 0;
}