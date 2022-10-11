#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cstring>

#include "sorted.h"

using namespace std;

int main(){
    char input[1000];
    SortedArray sortedarray;
    while(true){
        cin >> input;
        char * str = new char[strlen(input)+1];

        strcpy(str, input);

        if(strcmp(str, "ascend") == 0){
            for(int i=0; i<(sortedarray.GetSortedAscending()).size(); i++){
                cout << (sortedarray.GetSortedAscending())[i] << " ";
            }
            cout << endl;
        }
        else if(strcmp(str, "descend") == 0){
            for(int i=0; i<(sortedarray.GetSortedDescending()).size(); i++){
                cout << (sortedarray.GetSortedDescending())[i] << " ";
            }
            cout << endl;
        }
        else if(strcmp(str, "max") == 0){
            cout << sortedarray.GetMax() << endl;
        }
        else if(strcmp(str, "min") == 0){
            cout << sortedarray.GetMin() << endl;
        }
        else if(strcmp(str, "quit") == 0){
            break;
        }
        else{
            int num = atoi(input);
            sortedarray.AddNumber(num);
        }
        delete[] str;
    }
    return 0;
}