#include <iostream>
using namespace std;
class SoSimple{
    private:
    static int simObjcnt;

    public:
    SoSimple(){
        simObjcnt++;
        cout << simObjcnt << "번째 SoSimple 객체" << endl;
    }
};
int SoSimple::simObjcnt = 0;

class SoComplex{
    private:
    static int cmxObjcnt;

    public:
    SoComplex(){
        cmxObjcnt++;
        cout << cmxObjcnt << "번째 SoComplex 객체" << endl;
    }
    SoComplex(SoComplex &copy){
        cmxObjcnt++;
        cout << cmxObjcnt << "번째 SoComplex 객체" << endl;
    }
};
int SoComplex::cmxObjcnt = 0;

int main(){
    SoSimple sim1;
    SoSimple sim2;

    SoComplex cmx1;
    SoComplex cmx2;
    SoComplex();
    
    return 0;
}