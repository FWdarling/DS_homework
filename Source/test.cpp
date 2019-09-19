#include"q1.h"

using std::cout;
using std::endl;

int main(){
    StudentList sl;
    Student s("1853204", 18, "Darling", "Male", "Student");
    sl.Add("1719111", 12, "Lucy Brown", "Female", "Teacher");
    sl.sl.Add(s);
    sl.Display();
    return 0;
}