#include"../../Lab/vector.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    Vector<int32_t> customersA, customersB;
    int32_t cntA = 0, cntB = 0;
    int32_t count;
    cin >> count;
    for(int32_t i = 0; i < count; i++){
        int32_t customer;
        cin >> customer;
        if(customer % 2){
            cntA++;
            customersA.push_back(customer);
        }else{
            cntB++;
            customersB.push_back(customer);
        }
    }
    int32_t ia, ib;
    for(ia = 0, ib = 0; ia < cntA && ib < cntB; ia+= 2, ib++){
         cout << customersA[ia] << " ";
         if(ia + 1 < cntA) cout << customersA[ia + 1] << " ";
         cout << customersB[ib] << " ";
    }
    while(ia < cntA){
       cout << customersA[ia++] << " "; 
    }
    while (ib < cntB){
        cout << customersB[ib++] << " ";
    }
    cout << "\b" << endl;
    return 0;
}