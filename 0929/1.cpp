#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char **argv){
    int n = atoi(argv[argc-1]);
    string s = argv[1];
    for(int i=0; i<n; i++){
        cout << s << endl;
    }

    return 0;
}