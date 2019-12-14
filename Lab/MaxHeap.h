#ifndef MAXHEAP_H
#define MAXHEAP_H

#include"vector.h"

using std::cout;
using std::endl;

template<typename T>
class MaxHeap{
private:
    Vector<T> v;
    int32_t size;

public:
    MaxHeap(){
        size = 0;
    };
    MaxHeap(Vector<T> &vt){
        v = vt;
        size = vt.get_len();
    }
    ~MaxHeap() = default;

    // operator < overload needed
    void fitdown(int32_t ind);

    void fitup(int32_t ind);

    void add(T val);

    void remove(int32_t ind);

    int32_t get_index(T val);

    T display(int32_t ind);

    void print();

    //the function is used to sort
    void swap(int32_t ind1, int32_t ind2);

    Vector<T>& get_vector(){return v;}
};

template<typename T>
void MaxHeap<T>::fitdown(int32_t ind){
    if((ind << 1) + 1 >= size) return ;
    T s1 = v[(ind << 1) + 1], s2 = v[(ind << 1) + 2];
    if((ind << 1) + 2 >= size){
        if(v[ind] < s1){
            v[(ind << 1) + 1] = v[ind];
            v[ind] = s1;
        }
    }else{
        if((s2 < s1 || s2 == s1) && v[ind] < s1){
            v[(ind << 1) + 1] = v[ind];
            v[ind] = s1;
            fitdown((ind << 1) + 1);
        }else if(s1 < s2 && v[ind] < s2){
            v[(ind << 1) + 2] = v[ind];
            v[ind] = s2;
            fitdown((ind << 1) + 2);
        }
    }
}

template<typename T>
void MaxHeap<T>::fitup(int32_t ind){
    if(!ind) return;
    T f = v[(ind - 1) >> 1];
    if(f < v[ind]){
        v[(ind - 1) >> 1] = v[ind];
        v[ind] = f;
        fitup((ind - 1) >> 1);
    }
    return;
}

template<typename T>
void MaxHeap<T>::add(T val){
    v.push_back(val);
    size++;
    fitup(size - 1);
}

template<typename T>
void MaxHeap<T>::remove(int32_t ind){
    if(!size) {
        cout << "Heap is empty!" << endl;
        return;
    }
    if(ind == -1){
        cout << "Val is not in the heap!" << endl;
        return;
    }
    v[ind] = v[size - 1];
    v.pop_back();
    size--;
    fitdown(ind);
}

template<typename T>
int32_t MaxHeap<T>::get_index(T val){
    if(!size){
        cout << "Heap is empty!" << endl;
        return -1;
    }
    for(int32_t i = 0; i < size; i++){
        if(v[i] == val) return i;
    }
    return -1;
}

template<typename T>
T MaxHeap<T>::display(int32_t ind){
    if(ind >= size) {
        register T tem;
        cout << "index is out of table!" << endl;
        return tem;
    }
    return v[ind];
}

template<typename T>
void MaxHeap<T>::print(){
    if(!size){
        cout << "Heap is empty!" << endl;
    }
    for(int32_t i = 0; i < size; i++){
        cout << i << ":" << v[i] << endl;
    }
}

template<typename T>
void MaxHeap<T>::swap(int32_t ind1, int32_t ind2){
    v[ind1] = v[ind1] ^ v[ind2];
    v[ind2] = v[ind1] ^ v[ind2];
    v[ind1] = v[ind1] ^ v[ind2];
    size--;
}

#endif