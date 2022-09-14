#include <iostream>
using namespace std;

int sum(int x, int y, int z=0, int w=0)  // 디폴트값 설정
{
    return (x+y+z+w);
}

int main(){
    cout << sum(10, 15) << endl; // sum(10, 15, 0, 0)
    cout << sum(10, 15, 25) << endl; // sum(10, 15, 25, 0)
    cout << sum(10, 15, 25, 30) << endl; // sum(10, 15, 25, 30)
    
    return 0;
}
