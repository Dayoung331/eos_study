#include <iostream>
using namespace std;

double calc (double a,double b=10.0){
    cout<<"(double version)";
    return a*b;
}
double calc (float a){
    cout<<"(float version)";
    return a*a;
}

int main(){
    cout<<calc(5.0f)<<endl;  //float version
    cout<<calc(5.0f,8)<<endl;  //double version
    
    return 0;
}