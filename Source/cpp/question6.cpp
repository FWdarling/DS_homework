#include"../head/q6.h"

using std::string;
using std::cin;


int main(){
    cout << "Welcome to the family tree management system" << endl;
    Tree<string> family_tree;
    cout << "To establish a family, please enter ancestor's name: ";
    string ancestor;
    cin >> ancestor;
    build(family_tree, ancestor);
    char operation = 0;
    while(operation != 'Q'){
        instructions();
        cin >> operation;
        if(operation != 'Q'){
            string name, new_name;
            Vector<string> sons;
            int32_t count_son;
            switch (operation)
            {
            case 'A':
                cout << "Please enter the name of the member you want to query: ";
                cin >> name;
                search(family_tree, name);
                break;
            case 'B':
                cout << "Please enter the name of the person who needs to add child: ";
                cin >> name;
                cout << "Please enter the child's name: " << endl;
                cin >> new_name;
                insert(family_tree, name, new_name);
                break;
            case 'C':
                cout << "Please enter the members you want to establish a family for: ";
                cin >> name;
                cout << "Please enter the number of children in the family: ";
                cin >> count_son;
                cout << "The names of these children are: ";
                for(int32_t i = 0; i < count_son; i++){
                    string son;
                    cin >> son;
                    sons.push_back(son);
                }
                add(family_tree, name, sons);
                break;
            case 'D':
                cout << "Please enter the member whose name you want to modify: ";
                cin >> name;
                cout << "Please enter the member's modified name: ";
                cin >> new_name;
                modify(family_tree, name, new_name);
                break;
            case 'E':
                cout << "Please enter the member whose family you want to dissolve: ";
                cin >> name;
                fdelete(family_tree, name);
                break;
            default:
                cout << "Incorrect input. Please re-enter your operation." << endl;
                break;
            }
        }
    }
    return 0;
}