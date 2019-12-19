#include<iomanip>
#include<string>
#include"../../Lab/List.h"

using std::string;
using std::setw;
using std::endl;
using std::cout;
using std::left;
using std::ios;

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

    //number, age, name, sex, category
    void Add(string n,int32_t a, string na, string s, string c);

    void Add(Student st);

    void Print(ListNode<Student>* tar) const;

    void Print(Student* tar) const;

    void Display() const;

    //s is number when opt is 0 and s is name when opt is 1
    Student* findStudent(int32_t option, string s);

    //s is number when opt is 0 and s is name when opt is 1
    bool changeStudent(int32_t option, string s, Student new_info);

    //s is number when opt is 0 and s is name when opt is 1
    bool deleteStudent(int32_t option, string s);

    //s is number when opt is 0 and s is name when opt is 1
    bool insertStudent(int32_t position, Student s);
};



void StudentList::Add(string n, int32_t a, string na, string s, string c){
    Student st(n, a, na,  s, c);
    List<Student>& slt = this->sl;
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

void StudentList::Add(Student st){
    List<Student>& slt = this->sl;
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
    cout << std::setiosflags(ios::left) << setw(10) << student.num  << setw(15) << student.name << setw(10) << student.sex << setw(6) << student.age << setw(30) << student.cate << endl;
}

void StudentList::Print(Student* tar) const{
    cout << std::setiosflags(ios::left) << setw(10) << tar->num  << setw(15) << tar->name << setw(10) << tar->sex << setw(6) << tar->age << setw(30) << tar->cate << endl;
}

void StudentList::Display() const{
    cout << std::setiosflags(ios::left) << setw(10) << "Number"  << setw(15) << "Name"  << setw(10) << "Gender"  << setw(6) << "Age" << setw(30) << "Category" << endl;
    ListNode<Student>* cur = sl.get_head();
    while(cur){
        Print(cur);
        cur = cur->get_nxtptr();
    }
}

Student* StudentList::findStudent(int32_t option, string s){
    Student stu;
    if(!option) stu.num = s;
    else  stu.name = s;
    ListNode<Student>* res = sl.Find(stu);
    return res ? res->get_ptr() : nullptr;
}

bool StudentList::changeStudent(int32_t option, string s, Student new_info){
    Student stu;
    if(!option) stu.num = s;
    else  stu.name = s;
    return sl.Change(stu, new_info);
}

bool StudentList::deleteStudent(int32_t option, string s){
    Student stu;
    if(!option) stu.num = s;
    else  stu.name = s;
    return sl.Delete(stu);
}

bool StudentList::insertStudent(int32_t position, Student s){
    return sl.Insert(position - 1, s);
}



