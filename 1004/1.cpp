#include <iostream>

using namespace std;

class Student {
    private:
    string name_, id_, grade_;
    int midterm_, final_, hw1_, hw2_;

    public:
    void SetInfo(string name, string id){
        name_ = name, id_ = id;
    }
    void SetScores(int midterm, int final, int hw1, int hw2){
        midterm_ = midterm, final_ = final, hw1_ = hw1, hw2_ = hw2;
    }
    void ProcessGrade(){

    }
    string GetGrade() {
        return grade_;
    }
};

int main(){
    Student a_student;
    a_student.SetInfo("정다영", "13001");
    a_student.SetScores(99, 100, 95, 100);
    a_student.ProcessGrade();
    string grade = a_student.GetGrade();
}