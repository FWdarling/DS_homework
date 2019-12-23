#include"../../Lab/prim.h"

using std::cin;
using std::cout;
using std::endl;

void instructions(){
    cout << "You can choose the following actions:" << endl;
    cout << "A is creating grid vertex" << endl;
    cout << "B is adding grid edges" << endl;
    cout << "C is Generating shortest grid" << endl;
    cout << "D is displaying grid" << endl;
    cout << "Q is quiting the system" << endl;
    cout << endl;
    cout << "Please input your operation: ";
}

int32_t find_index(char c, Vector<char> &v){
    for(int32_t i = 0; i < v.get_size(); i++){
        if(c == v[i]) return i;
    }
    cout << "Incorrect point entered!" << endl;
    return -1;
}

void add_edge(MST& grid, int32_t n, Vector<char> &v){
    for(int32_t i = 0; i < n; i++){
        cout << "Please enter two vertices and edge: ";
        char ori, tar;
        int32_t len;
        cin >> ori >> tar >> len;
        grid.input(find_index(ori, v), find_index(tar, v), len);
    }
}

void generate(MST& grid, char start, Vector<char> &v){
    grid.generate(find_index(start, v));
}

void display(MST& grid, Vector<char> &v){
    Vector<Edge> mst = grid.get_mst();
    for(int32_t i = 0; i < mst.get_len(); i++){
        char ori = v[mst[i].get_ori()];
        char tar = v[mst[i].get_tar()];
        int32_t len = mst[i].get_len();
        cout << ori << "-<" << len << ">->" << tar << endl;
    }
    return;
}

