#include"vector.h"

using std::cout;
using std::endl;

template<typename T>
class Stack{
private:
    Vector<T> v;
    int32_t len;

public:
    Stack(){
        len = v.get_len();
    };
    Stack(Vector<T> vt, int32_t l = 0){
        v = vt;
        len = vt.get_len();
    }
    ~Stack() = default;

    void push(T val);

    void pop();

    T & top();

    const T& top() const;

    bool empty() {return !len;};

    int32_t size(){return len;}

};

template<typename T>
void Stack<T>::push(T val){
    v.push_back(val);
    len++;
}

template<typename T>
void Stack<T>::pop(){
    if(v.empty()) cout << "the stack is empty!" << endl;
    else{
        v.pop_back();
        len--;
    }
}

template<typename T>
T& Stack<T>::top(){
    if(v.empty()){
        static T t;
        cout << "the stack is empty!" << endl;
        return t;
    }
    return v[len - 1];
}

template<typename T>
const T& Stack<T>::top()const{
    if(v.empty()){
        static T t;
        cout << "the stack is empty!" << endl;
        return t;
    }
    return v[len - 1];
} 