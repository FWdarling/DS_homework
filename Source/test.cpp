#include"../Lab/prim.h"


using std::cout;
using std::endl;
using std::string;


int main(){
    MST m = MST(4);
    m.input(0, 1, 8);
    m.input(1, 2, 7);
    m.input(2, 3, 5);
    m.input(3, 0, 11);
    m.input(0, 2, 18);
    m.input(1, 3, 12);
    m.generate();
    for(int32_t i = 0; i < m.get_mst().get_len(); i++){
        cout << m.get_mst()[i].get_ori() << "   " << m.get_mst()[i].get_tar() << "    "<< m.get_mst()[i].get_len() << endl;
    }
    return 0;
}