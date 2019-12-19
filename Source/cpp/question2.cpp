#include"../../Lab/List.h"
#include<sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void input(std::stringstream& ss, List<int32_t>& l){
    cout << "Please enter several positive integers in non-descending order"  << endl;
    cout << "End the input with -1 and spaces separated by numbers" << endl;
    char buffer[65535];
    cin.getline(buffer, 65535);
    ss.str(buffer);
    int32_t current_num;
    ss >> current_num;
    while(current_num != -1){
        l.Add(current_num);
        ss >> current_num;
    }
    ss.clear();
}

int main(){
    List<int32_t> l1, l2;
    std::stringstream ss;
    input(ss, l1);
    input(ss, l2);
    ListNode<int32_t> *pt1 = l1.get_head(), *pt2 = l2.get_head();
    List<int32_t> result;
    while(pt1 || pt2){
        if(!pt1 || !pt2) {
            break;
        }else{
            int32_t next_value1 = pt1->get_value();
            int32_t next_value2 = pt2->get_value();
            if(next_value1 < next_value2){
                pt1 = pt1->get_nxtptr();
            }else if(next_value1 > next_value2){
                pt2 = pt2->get_nxtptr();
            }else{
                result.Add(next_value1);
                pt1 = pt1->get_nxtptr();
                pt2 = pt2->get_nxtptr();
            }
        }
    }
    cout << "The intersection of the two input sequences is£º" << endl;
    if(result.empty()) cout << "NULL" << endl;
    else {
        for(ListNode<int32_t>*lnptr = result.get_head(); lnptr != result.get_last(); lnptr = lnptr->get_nxtptr()){
            cout << lnptr->get_value() << " ";
        }
        cout << result.get_last()->get_value() <<endl;
    }
    return 0;
}