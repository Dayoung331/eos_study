#include <iostream>
#include "minmax.h"

using namespace std;

int main(int argc, char **argv){
    int N = argc-1;
    int max, min;
    int *arr = new int[N];
    for(int i=0; i<N; i++){
        arr[i] = atoi(argv[i+1]);
    }
    getMinMax(arr, N, min, max);
    cout << "min: " << min << endl;
    cout << "max: " << max;
}