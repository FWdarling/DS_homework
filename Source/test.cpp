#include"..\Lab\vector.h"

using std::cout;
using std::endl;
int main(){
    Vector<int> v;
    cout << v.get_len() << "  " << v.get_size() << endl;
    cout << v.empty() << endl;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }
    cout << v.get_len() << "  " << v.get_size() << endl;
    cout << v.empty() << endl;
    cout << v[5] << endl;
    v[5] = 0;
    cout << v[5] << endl;
    cout << v[10] << endl;
    Vector<int> v1 = v;
    cout <<  v1.get_len() << "  " << v1.get_size() << endl;
    cout << v1.empty() << endl;
    cout << v1[5] << endl;
    cout << v1[9] << endl;
    v1.pop_back();
    cout << v1[9] << endl;
    cout << v1.get_len() << endl;
    v1.push_back(-1);
    cout << v1[9] << endl;
    cout << v1.get_len() << endl;
    v1.clear();
    cout << v1.get_len() << "  " << v1.get_size() << endl;
    cout << v1.empty() << endl;
    return 0;
}