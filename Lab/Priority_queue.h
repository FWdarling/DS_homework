#ifndef PQ_H
#define PQ_H
#include"MaxHeap.h"

template<typename T>
class Priority_queue{
private:
    MaxHeap<T> heap;
    int32_t size;

public:
    Priority_queue(){
        size = 0;
    }

    ~Priority_queue() = default;

    void push(T val);

    void pop();

    T top();

    int32_t get_size() {return size;};

    bool empty(){return !size;}
};

template<typename T>
void Priority_queue<T>::push(T val){
    size++;
    heap.add(val);
}

template<typename T>
void Priority_queue<T>::pop(){
    int32_t index = 0;
    heap.remove(index);
    size--;
}

template<typename T>
T Priority_queue<T>::top(){
    if(!size) {
        register T tem;
        cout << "Heap is empty!" << endl;
        return tem;
    }
    return heap.display(0);
}
#endif

