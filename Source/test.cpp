#include"q1.h"

using std::cout;
using std::endl;

int main(){
    StudentList sl;
    Student s1("1234", 18, "wang", "男", "工程师");
    Student s2("4321", 18, "li", "男", "工程师");
    cout << sl.sl.empty () << endl;
    sl.sl.Add (s1);
    sl.sl.Add (s2);
    cout << sl.sl.empty () << endl;
    cout << sl.sl.get_len () << endl;
    sl.Display ();
    sl.Print(sl.FindStudent(0, "4321"));
    sl.Print(sl.FindStudent(1, "wang"));
    cout << sl.DeleteStudent(1, "LI");
    sl.Display();
    cout << sl.DeleteStudent(1, "li");
    sl.Display();
    sl.sl.Add(Student("abcd", 10, "hahah", "女", "班主任"));
    sl.Display();
    cout << sl.ChangeStudent(0, "abcd", Student("77", 7, "7", "77", "777"));
    sl.Display();
    return 0;
}