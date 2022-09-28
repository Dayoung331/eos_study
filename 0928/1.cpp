#include <iostream>
#include <string>

using namespace std;

typedef struct{
    string name;
    double score;
} Person;

int main(int argc, const char **argv){
    int N = (argc-1)/2;
    Person *students = new Person[N];
    int i=0, j=1;
    while(i<N){
        students[i].name = argv[j];
        students[i].score = atof(argv[j+1]);
        i+=1;
        j+=2;
    }

    for(int i=0; i<N; i++){
        cout << "Name:" << students[i].name << ", Score:" << students[i].score << endl;
    }

    delete []students;
    return 0;
}