#include"../Lab/MaxHeap.h"

using std::cout;
using std::endl;

int main(){
    MaxHeap<int> mh;
    mh.print();
    mh.add(5);
    mh.add(-7);
    mh.print();
    for(int i = 0; i < 5; i++){
        mh.add(i);
    }
    mh.print();
    mh.get_index(5);
    mh.remove(5);
    mh.print();
    mh.remove(-7);
    mh.print();
    return 0;
}