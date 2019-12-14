#include"../Lab/sort.h"


using std::cout;
using std::endl;
using std::string;


int main(){
   Vector<int32_t> v;
   for(int32_t i = 10; i >= 0; i--){
       v.push_back(i);
   }
   quickSort(v, 0, 11);
   for(int32_t i = 0; i <= 10; i++){
       cout << v[i] << endl;
   }
   v.clear();
    return 0;
}