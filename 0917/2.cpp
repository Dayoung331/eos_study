#include <iostream>
#include <stdlib.h>

using namespace std;
void TestFunction(int n) {
    int* int_instance = new int;
    int* variable_size_array = new int[n];
    *int_instance = 10;
    for (int i = 0; i < n; ++i){
        cin >> variable_size_array[i];
    }

    delete int_instance;
    delete[] variable_size_array;
}

int main() {
    TestFunction(3);
    
    return 0;
}
