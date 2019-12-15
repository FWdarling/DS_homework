#include"q1.h"

using std::cin;
using std::string;

Student input(){
    cout << "Please enter the candidate's exam number, age, name, gender(male or female) and registration category" << endl;
    cout << "Tip: use underscores'_' instead of Spaces' ' when entering a name" << endl;
    Student aStudent;
    string exam_number, name, gender, category;
    int32_t age;
    cin >> exam_number >> age >> name >> gender >> category;
    if(age <= 0 || age > 150) {
        cout << "error: Unreasonable input age!  Please re-enter the candidate information." << endl;
    }
    else if(gender[0] != 'm' && gender[0] != 'f') {
         cout << "error: Unreasonable input gender£¡ Please re-enter the candidate information." << endl;
    }else {
       aStudent.set_value(exam_number, age, name, gender, category);
       return aStudent;
    }
    return aStudent;
}

int main(){
    cout << "Please input information to build the examinee information system!" << endl;
    cout << "Please enter the number of examinee: ";
    StudentList aStudentList;
    int32_t count;
    cin >> count;
    for(int32_t i = 0; i < count;i++){
        Student aStudent = input();
        if(aStudent.get_age()) aStudentList.Add(aStudent);
    }
    aStudentList.Display();
    bool loop_continue = true;
    while(loop_continue){
        cout << "Please enter what you want to do(1 is insert, 2 is delete, 3 is search, 4 is change, 5 is statistics, 0 is exit):" << endl;
        int32_t operation;
        cin >> operation;
        int32_t choice;
        int32_t insert_position;
        string change_info;
        Student aStudent;
        switch (operation)
        {
            case 0:
                loop_continue = false;
                break;
            case 1:
                cout << "Please enter the position you want to insert: ";
                cin >> insert_position;
                cout << endl;
                aStudent = input();
                if(aStudent.get_age()) aStudentList.insertStudent(insert_position, aStudent);
                break;

            case 2:
                cout << "Please select the student information you want to enter (0 for exam number 1 for name): ";
                cin >> choice;
                cout << endl;
                if(!choice){
                    cout <<"Please enter the exam number of the candidate you want to delete: ";
                    string delete_number;
                    cin >> delete_number;
                    cout << endl;
                    if(!aStudentList.deleteStudent(0, delete_number)) cout << "error: The exam number dosen't exit!" << endl;
                }else if(choice == 1){
                    cout <<"Please enter the student name of the candidate you want to delete: ";
                    string delete_name;
                    cin >> delete_name;
                    cout << endl;
                    if(!aStudentList.deleteStudent(1, delete_name)) cout << "error: The name doesn't exit!" << endl;
                }else{
                    cout << "Selection error!" << endl;
                }
                break;

            case 3:
                cout << "Please select the student information you want to enter (0 for exam number 1 for name): ";
                cin >> choice;
                cout << endl;
                if(!choice){
                    cout <<"Please enter the exam number of the candidate you want to search: ";
                    string search_number;
                    cin >> search_number;
                    cout << endl;
                    Student* find_res = aStudentList.findStudent(0, search_number);
                    aStudentList.Print(find_res);
                }else if(choice == 1){
                    cout <<"Please enter the student name of the candidate you want to search: ";
                    string search_name;
                    cin >> search_name;
                    cout << endl;
                    Student* find_res = aStudentList.findStudent(1, search_name);
                    aStudentList.Print(find_res);
                }else{
                    cout << "Selection error!" << endl;
                }
                break;

            case 4:
                cout << "Please select the student information you want to enter (0 for exam number 1 for name): ";
                int32_t choice;
                cin >> choice;
                cout << endl;
                if(!choice){
                    cout <<"Please enter the exam number of the candidate you want to change: ";
                    cin >> change_info;
                    cout << endl;
                }else if(choice == 1){
                    cout <<"Please enter the student name of the candidate you want to change: ";
                    cin >> change_info;
                    cout << endl;
                }else{
                    cout << "Selection error!" << endl;
                    break;
                }
                aStudent = input();
                aStudentList.changeStudent(choice, change_info, aStudent);
                break;

            case 5:
                aStudentList.Display();
                break;

            default:
                cout << "Choose error! Please input again." << endl;
                break;
        }
    }
    return 0;
}