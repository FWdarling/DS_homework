#include<iostream>


template<typename T>
class ListNode{

private:
    T value;
    ListNode* nxt;

public:

    ListNode(T v, ListNode* n = nullptr): value(v){
        nxt = n;
    }
    ~ListNode() = default;

    T get_value() const{ return value;}

    ListNode* get_nxtptr() const{return nxt;}

    void set_value(T v){value = v;}

    void set_nxtptr(ListNode* nxtptr){nxt = nxtptr; }

};

template<typename T>
class List{
private:
    int32_t len;
    //head is a pointer to the first student node and last is a pointer to the last node
    ListNode<T>* head, *last;

public:
    List(int32_t l = 0):len(l){
        head = nullptr;
        last = nullptr;
    }
    ~List(){
        ListNode<T>* cur = this->head;
        while(cur){
            ListNode<T>* nxt = cur->nxt;
            delete(cur);
            cur = nxt;
        }
        delete this;
    };
    
    void Add(T val);

    ListNode<T>* Find(T val) const;

    bool Insert(int32_t ind, T val);

    // equals defination needed
    bool Change(T val, T new_val);

    bool Delete(T val);

    void Clear();

    int32_t get_len() const{return len;}

    ListNode<T>* get_head() const{return head;}

    ListNode<T>* get_last() const{return last;}

    void set_head(ListNode<T>* h){head = h;}

    void set_last(ListNode<T>* l){last = l;}

    void set_len(int32_t l){len = l;}

};

template<typename T>
void List<T>::Add(T val){
    if(!this->head){
        head = last = new ListNode<T>(val);
    }
    else{
        last = last->nxt = new ListNode<T>(val);
    }
    this->len++;
}


//if it cant find the number, then return nullptr, 
template<typename T>
ListNode<T>* List<T>::Find(T val) const{
    ListNode<T>* cur = this->head;
    while(cur){
        if(cur->get_value() == val){
            return cur;
        }
        cur = cur->nxt;
    }
    return cur;
}

//behind insert 
//the index includes zero
template<typename T>
bool List<T>::Insert(int32_t ind, T val){
    if(ind >= this->len) return false;
    ListNode<T>* cur = this->head;
    while(cur){
        if(!ind){
            ListNode<T>* next = cur->nxt;
            cur->nxt = new ListNode<T>(val, next);
            this->len++;
            return true;
        }
        cur = cur->nxt;
        ind--;
    }
    return false;
}

template<typename T>
bool List<T>::Change(T val, T new_val){
    ListNode<T>* tar = this->Find(val);
    if(tar){
        tar->set_value(new_val);
        return true;
    }
    return false;
}

template<typename T>
bool List<T>::Delete(T val){
    ListNode<T>* cur = this->head;
    ListNode<T>* lst = cur;
    while(cur){
        if(cur->get_value() == val){
            lst->nxt = cur->nxt;
            delete cur;
            this->len--;
            return true;
        }
        lst = cur;
        cur = cur->nxt;
    }
    return false;
}

template<typename T>
void List<T>::Clear(){
    ListNode<T>* cur = this->head;
    while(cur){
        ListNode<T>* nxt = cur->nxt;
        delete(cur);
        cur = nxt;
    }
    len = 0;
    head = last = nullptr;
}

