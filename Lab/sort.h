#ifndef SORT_H
#define SORT_H
#include"vector.h"
#include<cstdlib>
#include<ctime>

int32_t times;

void generate(int32_t number, Vector<int32_t> &v, int32_t max_num){
    srand((unsigned)time(nullptr));
    for(int32_t i = 0; i < number; i++){
        int32_t tem = rand() % max_num;
        v.push_back(tem);
    }
}

//To avoid the cost of function calls to affect the test results,
//i won't use tje exchange function here.
/*
void exchange(Vector<int32_t> &v, int32_t ind1, int32_t ind2){
     v[ind1] = v[ind1] ^ v[ind2];
     v[ind2] = v[ind1] ^ v[ind2];
     v[ind1] = v[ind1] ^ v[ind2];
}
*/

// data structure ---------- Vector<int32_t>
// Worst time complexity ---- O (n ^ 2)
// Optimal time complexity --- O (n)
// average time complexity ---- O (n ^ 2)
// required auxiliary space ------ O (1)
// stability ------------ stable
void bubbleSort(Vector<int32_t> &v){
    int32_t len = v.get_len();
    if(len <= 1) return;
    for(int32_t i = 0; i < len - 1; i++){
        for(int32_t j = 0; j < len - i - 1; j++){
            times++;
            if(v[j] > v[j + 1]) {
                v[j] = v[j] ^ v[j + 1];
                v[j + 1] = v[j] ^ v[j + 1];
                v[j] = v[j] ^ v[j + 1];

            }
        }
    }
    cout << "The number of comparison for bubble sorting is: "<< times << endl;
    times = 0;
}

// data structure ---------- Vector<int32_t>
// Worst time complexity ---- O (n ^ 2)
// Optimal time complexity --- O (n ^ 2)
// average time complexity ---- O (n ^ 2)
// required auxiliary space ------ O (1)
// stability ------------ stable
void selectionSort(Vector<int32_t> &v){
    int32_t len = v.get_len();
    if(len <= 1) return;
    for(int32_t i = 0; i < len - 1; i++){
        int32_t min_index = i;
        for(int32_t j = i + 1; j < len; j++){
            if(v[j] < v[min_index]) min_index = j;
            times++;
        }
        if(min_index != i) {
            v[i] = v[i] ^ v[min_index];
            v[min_index] = v[i] ^ v[min_index];
            v[i] = v[i] ^ v[min_index];
            times++;
        }
    }
    cout << "The number of comparison for selection sorting is: "<< times << endl;
    times = 0;
}

// data structure ---------- Vector<int32_t>
// Worst time complexity ---- O (n ^ 2)
// Optimal time complexity --- O (n)
// average time complexity ---- O (n ^ 2)
// required auxiliary space ------ O (1)
// stability ------------ stable
void insertionSort(Vector<int32_t> &v){
    int32_t len = v.get_len();
    if(len <= 1) return;
    for(int32_t i = 1; i < len; i++){
        int32_t correct_position = 0;
        for(int32_t j = i - 1; j >= 0; j--){
            if(v[j] <= v[i]){
                correct_position = j + 1;
                break;
            }
            times++;
            int32_t current_number = v[i];
            for(int32_t j = i; j > correct_position; j--){
                v[j] = v[j - 1];
                times++;
            }
            v[correct_position] = current_number;
        }
    }
    cout << "The number of comparison for insertion sorting is: "<< times << endl;
    times = 0;
}

// data structure ---------- Vector<int32_t>
// Worst time complexity ----
// Optimal time complexity --- O (n)
// average time complexity ----
// required auxiliary space ------ O (1)
// stability ------------ unstable
void shellSort(Vector<int32_t> &v){
    int32_t len = v.get_len();
    if(len <= 1) return;

    for(int32_t div = len >> 1; div >= 1; div >>= 1){
        for(int32_t i = div; i < len; i++){
            int32_t j = i - div;
            int32_t current = v[i];
            while(j >= 0 && v[j] > current){
                times++;
                v[j + div] = v[j];
                j -= div;
            }
            v[j + div] = current;
        }
    }
    cout << "The number of comparison for shell sorting is: "<< times << endl;
    times = 0;
}

// data structure ---------- Vector<int32_t>
// Worst time complexity ---- O(n^2)
// Optimal time complexity --- O(nlogn)
// average time complexity ---- O(nlogn)
// required auxiliary space ------ generally O (logn), the worst is O (n)
// stability ------------ unstable
void quickSort(Vector<int32_t> &v, int32_t left, int32_t right){
    int32_t len = v.get_len();
    if(left + 1 >= right) return;
    srand((unsigned)time(nullptr));
    int32_t pivot_index = rand() % (right - left) + left;
    int32_t pivot = v[pivot_index];
    int32_t left_to_sort = left, right_to_sort = right - 1;
    while(left_to_sort < right_to_sort) {
        times++;
        while (v[left_to_sort] < pivot) {
            left_to_sort++;
            times++;
        }
        while (v[right_to_sort] >= pivot && right_to_sort >= 0) {
            if (!right_to_sort) {
               break;
            }
            right_to_sort--;
            times++;
        }
        int32_t temp = v[left_to_sort];
        v[left_to_sort] = v[right_to_sort];
        v[right_to_sort] = temp;
        left_to_sort++;
        right_to_sort--;
    }
    quickSort(v, left, left_to_sort);
    quickSort(v, left_to_sort, right);
    if(left == 0 && right == v.get_len()){
        cout << "The number of comparison for quick sorting is: "<< times << endl;
        times = 0;
    }
}

void fitdown(int32_t ind, Vector<int32_t> &v){
    if((ind << 1) + 1 >= v.get_len()) return ;
    int32_t s1 = v[(ind << 1) + 1], s2 = v[(ind << 1) + 2];
    times++;
    if((ind << 1) + 2 >= v.get_len()){
        if(v[ind] < s1){
            v[(ind << 1) + 1] = v[ind];
            v[ind] = s1;
        }
    }else{
        if((s2 < s1 || s2 == s1) && v[ind] < s1){
            v[(ind << 1) + 1] = v[ind];
            v[ind] = s1;
            fitdown((ind << 1) + 1, v);
        }else if(s1 < s2 && v[ind] < s2){
            v[(ind << 1) + 2] = v[ind];
            v[ind] = s2;
            fitdown((ind << 1) + 2, v);
        }
    }
}
// data structure ---------- Vector<int32_t>
// Worst time complexity ---- O(nlogn)
// Optimal time complexity --- O(nlogn)
// average time complexity ---- O(nlogn)
// required auxiliary space ------ O(n)
// stability ------------ stable
void heapSort(Vector<int32_t> &v){
    int32_t len = v.get_len();
    if(len <= 1) return;
    for(int32_t i = (len >> 1) - 1; i >= 0; i--){
        fitdown(i, v);
    }
    while(len > 1){
        v[0] = v[0] ^ v[--len];
        v[len] = v[0] ^ v[len];
        v[0] = v[0] ^ v[len];
        fitdown(0, v);
    }
    cout << "The number of comparison for heap sorting is: "<< times << endl;
    times = 0;
}

// data structure ---------- Vector<int32_t>
// Worst time complexity ---- O(nlogn)
// Optimal time complexity --- O(nlogn)
// average time complexity ---- O(nlogn)
// required auxiliary space ------ O(n)
// stability ------------ unstable
void mergeSort(Vector<int32_t> &v, int32_t left, int32_t right){
    if(left + 1 >= right) return;
    int32_t mid = (left + right) >> 1;
    mergeSort(v, left, mid);
    mergeSort(v, mid, right);
    Vector<int32_t> temp;
    int32_t index_l = left, index_r = mid, index_cnt = 0;
    while(index_cnt < right - left){
        times++;
        if(index_l == mid || (index_r < right && v[index_l] > v[index_r])) {
            temp.push_back(v[index_r++]);
            index_cnt++;
        } else if(index_r == right || v[index_l] <= v[index_r]){
            temp.push_back(v[index_l++]);
            index_cnt++;
        }
    }
    for(int i = 0; i < right - left; i++){
        v[left + i] = temp[i];
    }
    if(!left && right == v.get_len()){
        cout << "The number of comparison for merge sorting is: "<< times << endl;
        times = 0;
    }
}

// data structure ---------- Vector<int32_t>
// Worst time complexity ---- O(n ^ 2)
// Optimal time complexity --- O(2n * d)
// average time complexity ---- O(n)
// required auxiliary space ------ O(n + k)
// stability ------------ stable
void radixSort(Vector<int32_t> &v){
    int32_t len = v.get_len();
    if(len <= 1) return;
    int32_t res = 10, div = 1;
    bool is_not_max_digit = true;
    Vector<int32_t> counter[10];
    while(is_not_max_digit){
        is_not_max_digit = false;
        for(int32_t i = 0; i < len; i++){
            if(v[i] / res) is_not_max_digit = true;
            int32_t index = v[i] % res / div;
            counter[index].push_back(v[i]);
            times++;
        }
        int32_t radix = 0, index = 0;
        for(int32_t i = 0; i < len; i++){
            times++;
            if(index == counter[radix].get_len()){
                v[i] = counter[++radix][0];
                index = 0;
            }else{
                v[i] = counter[radix][index++];
            }
        }
        for(int32_t i = 0; i < 10; i++){
            counter[i].clear();
        }
        res *= 10; div *= 10;
    }
    cout << "The number of moving data for radix sorting is: "<< times << endl;
    times = 0;
}

#endif