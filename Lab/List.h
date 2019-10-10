#include<iostream>


template<typename T>
class ListNode{

private:
    T value;
    ListNode* nxt;

public:

    ListNode() = default;
    ListNode(T v, ListNode* n = nullptr): value(v){
        nxt = n;
    }
    ~ListNode() = default;

    T get_value() const{ return value;}

    T* get_ptr() { return &value;}

    ListNode* get_nxtptr() const{return nxt;}

    void set_value(T v){value = v;}

    void set_nxtptr(ListNode* nxtptr){nxt = nxtptr; }

};

template<typename T>
class List{
private:
    int32_t len;
    //head is a pointer to the first list node and last is a pointer to the last node
    ListNode<T>* head, *last;

public:
    List(int32_t l = 0):len(l){
        head = nullptr;
        last = nullptr;
    }
    ~List(){
        ListNode<T>* cur = this->head;
        while(cur){
            ListNode<T>* next = cur->get_nxtptr();
            delete(cur);
            cur = next;
        }
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

    void set_head(ListNode<T>* h) {head = h;}

    void set_last(ListNode<T>* l) {last = l;}

    void set_len(int32_t l){len = l;}

    bool empty(){return !len;}

};

template<typename T>
void List<T>::Add(T val){
    if(!this->head){
        head = last = new ListNode<T>(val);
    }
    else{

        ListNode<T>* new_ptr = new ListNode<T>(val);
        last->set_nxtptr(new_ptr);
        last = new_ptr;
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
        cur = cur->get_nxtptr();
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
            ListNode<T>* next = cur->get_nxtptr();
            ListNode<T>* new_ptr = new ListNode<T>(val, next);
            cur->set_nxtptr(new_ptr);
            this->len++;
            return true;
        }
        cur = cur->get_nxtptr();
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
            if(cur == head){
                if(head == last){
                    head = last = nullptr;
                }
                head = head->get_nxtptr ();
                len--;
                delete cur;
                return true;
            }
            lst->set_nxtptr(cur->get_nxtptr());
            delete cur;
            this->len--;
            last = lst;
            return true;
        }
        lst = cur;
        cur = cur->get_nxtptr();
    }
    return false;
}

template<typename T>
void List<T>::Clear(){
    ListNode<T>* cur = this->head;
    while(cur){
        ListNode<T>* nxt = cur->get_nxtptr();
        delete(cur);
        cur = nxt;
    }
    len = 0;
    head = last = nullptr;
}

