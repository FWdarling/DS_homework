#include"../Lab/stack.h"

using std::cout;
using std::endl;

int main(){
    Stack<int> s;
    cout <<s.empty() << endl;
    cout << s.top() << endl;
    s.pop();
    s.push(1);
    s.push(2);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.push(0);
    cout << s.top() << endl;
    cout << s.empty() << endl;
    s.pop();s.pop();
    cout << s.top() << endl << s.empty() << endl;
    return 0;
}