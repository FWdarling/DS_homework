#include<iomanip>
#include<string>
#include"../Lab/List.h"

using std::string;
using std::setw;
using std::endl;
using std::cout;

class Student{
public:
    int32_t age;
    string num, name, sex, cate;

    Student(string n = "", int32_t a = 0, string na = "", string s = "", string c = "")
            : num(n), age(a){
        name = na;
        sex = s;
        cate = c;
    }
    ~Student() = default;

    string get_num(){
        return this->num;
    }

    int32_t get_age(){
        return this->age;
    }

    string get_name(){
        return this->name;
    }

    string get_sex(){
        return this->sex;
    }

    string get_cate(){
        return this->cate;
    }

    void set_value(string n,int32_t a, string na, string s, string c){
        name = na;
        sex = s;
        cate = c;
        num = n;
        age = a;
    }

    bool operator == (const Student &a) const{
        return num == a.num || name == a.name;
    }
};


class StudentList{

public:
    List<Student> sl;

public:

    void Add(string n,int32_t a, string na, string s, string c);

    void Print(ListNode<Student>* tar) const;

    void Print(Student* tar) const;

    void Display() const;

    //s is numberwhen opt is 0 and s is name when opt is 1
    Student* FindStudent(int option, string s);

    bool ChangeStudent(int option, string s, Student new_info);

    bool DeleteStudent(int option, string s);
};



void StudentList::Add(string n, int32_t a, string na, string s, string c){
    Student st(n, a, na,  s, c);
    List<Student> slt = this->sl;
    if(!slt.get_head()){
        ListNode<Student>* lnsp = new ListNode<Student>(st);
        slt.set_head(lnsp);
        slt.set_last(lnsp);
    }
    else{
        ListNode<Student>*  nxt = new ListNode<Student>(st);
        slt.get_last()->set_nxtptr(nxt);
        slt.set_last(nxt);
    }
    sl.set_len(sl.get_len() + 1);
}

void StudentList::Print(ListNode<Student>* tar) const{
    Student student = tar->get_value();
    cout << setw(10) << student.num << setw(10) << student.name << setw(6) << student.sex << setw(8) << student.age << student.cate << endl;
}

void StudentList::Print(Student* tar) const{
    cout << setw(10) << tar->num << setw(10) << tar->name << setw(6) << tar->sex << setw(8) << tar->age << tar->cate << endl;
}

void StudentList::Display() const{
    cout << setw(10) << "考号" << setw(10) << "姓名" << setw(6) << "性别" << setw(8) << "年龄" << "报考类别" << endl;
    ListNode<Student>* cur = sl.get_head();
    while(cur){
        Print(cur);
        cur = cur->get_nxtptr();
    }
}

Student* StudentList::FindStudent(int option, string s){
    Student stu;
    if(!option) stu.num = s;
    else  stu.name = s;
    ListNode<Student>* res = sl.Find(stu);
    return res ? res->get_ptr() : nullptr;
}

bool StudentList::ChangeStudent(int option, string s, Student new_info){
    Student stu;
    if(!option) stu.num = s;
    else  stu.name = s;
    return sl.Change(stu, new_info);
}

bool StudentList::DeleteStudent(int option, string s){
    Student stu;
    if(!option) stu.num = s;
    else  stu.name = s;
    return sl.Delete(stu);
}



