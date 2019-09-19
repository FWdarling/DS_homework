//
// Created by FWDarling on 9/19/2019.
//

#ifndef DSTEST_VECTOR_H
#define DSTEST_VECTOR_H

#endif //DSTEST_VECTOR_H
#include<iostream>

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

    Vector<T>(int32_t s = 1024) :size(s){
        len = 0;
        ptr = new T[s];
        end = ptr;
    }

    ~Vector<T>(){
        delete [] ptr;
        end = nullptr;
    };

    int32_t get_size() const {return size;}

    int32_t get_len() const {return len;}

    bool empty(){return !len;}

    T& operator [] (int32_t ind);

    const T& operator [] (int32_t ind)const;

    Vector<T>& operator = (Vector<T> v);

    void resize(int32_t s);

    void push_back(T a);

    void pop_back();

    void clear();

};

template<typename T>
void Vector<T>::shrink(){
    if(len < (size << 2)){
        this->resize(len << 1);
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
    for(int i = 0; i < this->len; i++){
        new_ptr[i] = this->ptr[i];
    }
    delete[] this->ptr;
    this->ptr = new_ptr;
    this->end = ptr + (len ? len - 1 : 0);
    this->size = s;
}

template<typename T>
void Vector<T>::push_back(T a){
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
    if(ind >= len || ind < 0) {
        std::cout << "out of the table" << std::endl;
        return t;
    }
    return ptr[ind];
}

template<typename T>
const T& Vector<T>::operator [] (int32_t ind) const{
    static T t;
    if(ind >= len || ind < 0) {
        std::cout << "out of the table" << std::endl;
        return t;
    }
    return ptr[ind];
}

template<typename T>
Vector<T>& Vector<T>::operator =(Vector<T> v){
    size = v.get_size();
    len = v.get_len();
    delete [] ptr;
    this->ptr = new T[size];
    for(int i = 0; i < len; i++){
        ptr[i] = v[i];
    }
    end = ptr + (len ? len - 1 : 1);
    return *this;
}