#include <iostream>

class Point{
    private:
        int x;
        int y;
    public:
        void setXY(int a, int b){
    x=a; y=b;
    }
};

int main(void){
    Point p1;
    p1.setXY(3, 4);
    return 0;
}