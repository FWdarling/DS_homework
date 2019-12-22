#include"../../Lab/Priority_queue.h"

using std::cin;
using std::cout;
using std::endl;

class WoodLen{
    int32_t len;

public:
    WoodLen(int32_t l = 0):len(l){};
    bool operator < (WoodLen &a) const{
        return len > a.len;
    }
    bool operator == (WoodLen &a) const{
        return len == a.len;
    }
    int32_t get_len(){return len;}
};

int main(){
    Priority_queue<WoodLen> huffman;
    int32_t n;
    cin >> n;
    if(n < 1) {
        cout << "Error: illegal arguments input!" << endl;
    }
    for(int32_t i = 0; i< n; i++){
        int32_t length;
        cin >> length;
        WoodLen wood(length);
        huffman.push(wood);
    }
    int32_t cost = 0;
    while(huffman.get_size() > 1){
        WoodLen wl1 = huffman.top();huffman.pop();
        WoodLen wl2 = huffman.top();huffman.pop();
        WoodLen sum(wl1.get_len() + wl2.get_len());
        huffman.push(sum);
        cost += sum.get_len();
    }
    cout << cost << endl;
    return 0;
}