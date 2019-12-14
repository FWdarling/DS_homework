//
// Created by FWDarling on 9/19/2019.
//

#ifndef DSTEST_VECTOR_H
#define DSTEST_VECTOR_H

#include<iostream>

using std::cout;
using std::endl;

template<typename T>
class Vector{

private:
    int32_t size, len;
    T* ptr;
    T* end;

//to avoid vesting memory, when len * 4 < size then shrink
    void shrink();

    void expand();
public:

    Vector<T>(int32_t s = 64) :size(s){
        len = 0;
        ptr = new T[s];
        end = ptr;
    }

    ~Vector<T>(){
        if(ptr) delete [] ptr;
        end = nullptr;
    };

    int32_t get_size() const {return size;}

    int32_t get_len() const {return len;}

    bool empty(){return !len;}

    T& operator [] (int32_t ind);

    const T& operator [] (int32_t ind)const;

    Vector<T>& operator = (Vector<T> &v);

    void resize(int32_t s);

    void push_back(T& a);

    void pop_back();

    void clear();

    int32_t find(T val);

    bool Delete(int32_t ind);

};

template<typename T>
void Vector<T>::shrink(){
    if(len < (size << 2)){
        this->resize(len ? len << 1 : size << 2);
    }
}

template<typename T>
void Vector<T>:: expand(){
    if(len == size){
        this->resize(size << 1);
    }
}

template<typename T>
void Vector<T>::resize(int32_t s){
    T* new_ptr = new T[s];
    for(int32_t i = 0; i < this->len; i++){
        new_ptr[i] = this->ptr[i];
    }
    delete[] this->ptr;
    this->ptr = new_ptr;
    this->end = ptr + (len ? len - 1 : 0);
    this->size = s;
}

template<typename T>
void Vector<T>::push_back(T& a){
    ptr[len++] = a;
    end = ptr + len - 1;
    expand();
}

template<typename T>
void Vector<T>::pop_back(){
    len--;
    end = ptr + (len ? len - 1 : 1);
    shrink();
}

template<typename T>
void Vector<T>::clear(){
    end = ptr;
    len = 0;
    shrink();
}

template<typename T>
T& Vector<T>::operator [](int32_t ind){
    static T t;
    if(ind >= size || ind < 0) {
        std::cout << "index is " << ind << " but size is " << size << endl;
        std::cout << "vector is out of the table" << std::endl;
        return t;
    }
    return ptr[ind];
}

template<typename T>
const T& Vector<T>::operator [] (int32_t ind) const{
    static T t;
    if(ind >= size || ind < 0) {
        std::cout << "index is " << ind << " but size is " << size << endl;
        std::cout << "vector is out of the table" << std::endl;
        return t;
    }
    return ptr[ind];
}

template<typename T>
Vector<T>& Vector<T>::operator = (Vector<T> &v){
    size = v.get_size();
    len = v.get_len();
    T* temptr = ptr;
    this->ptr = new T[size];
    if(temptr)     delete [] temptr;
    for(int i = 0; i < len; i++){
        ptr[i] = v[i];
    }
    end = ptr + (len ? len - 1 : 1);
    return *this;
}

template<typename T>
int32_t Vector<T>::find(T val){
    for(int32_t i = 0; i < this->get_len(); i++){
        if((*this)[i] == val) {
            return i;
        }
    }
    return -1;
}

template<typename T>
bool Vector<T>::Delete(int32_t ind){
    if(ind < 0 || ind >= len){
        cout << "the index is out of table!" << endl;
        return false;
    }
    for(int i = ind; i < len - 1; i++){
        ptr[i] = ptr[i + 1];
    }
    pop_back();
    return true;
}

#endif //DSTEST_VECTOR_H