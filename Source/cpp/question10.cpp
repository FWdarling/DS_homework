#include"../../Lab/sort.h"

using std::cin;

void instructions(){
    cout << "You can choose the following sort algorithms:" << endl;
    cout << "1 is bubblesort" << endl;
    cout << "2 is selectionsort" << endl;
    cout << "3 is insertionsort" << endl;
    cout << "4 is shellsort" << endl;
    cout << "5 is quicksort" << endl;
    cout << "6 is heapsort" << endl;
    cout << "7 is mergesort" << endl;
    cout << "8 is radixsort" << endl;
    cout << "0 is quiting the system" << endl;
    cout << endl;
    cout << "Please input your choice: ";
}

int main(){
    cout << "Welcome to the sort comparing system" << endl;
    cout << "Please enter the number of random numbers to be generated: ";
    int32_t number;
    cin >> number;
    Vector<int32_t> v(number);
    cout << "Please enter a random number maximum value (do not exceed intmax): ";
    int32_t max_num;
    cin >> max_num;
    generate(number, v, max_num);
    char operation = 0;
    while(operation != '0'){
        instructions();
        cin >> operation;
        if(operation != '0'){
            Vector<int32_t> v_copy;
            v_copy.operator= (v);
            time_t start, end;
            double cost;
            switch (operation)
            {
                case '1':
                    time(&start);
                    bubbleSort(v_copy);
                    time(&end);
                    cost = difftime(end, start);
                    cout << "Bubblesort takes time: " << cost << endl;
                    break;

                case '2':
                    time(&start);
                    selectionSort(v_copy);
                    time(&end);
                    cost = difftime(end, start);
                    cout << "Selectionsort takes time: " << cost << endl;
                    break;

                case '3':
                    time(&start);
                    insertionSort(v_copy);
                    time(&end);
                    cost = difftime(end, start);
                    cout << "Insertionsort takes time: " << cost << endl;
                    break;

                case '4':
                    time(&start);
                    shellSort(v_copy);
                    time(&end);
                    cost = difftime(end, start);
                    cout << "Shellsort takes time: " << cost << endl;
                    break;

                case '5':
                    time(&start);
                    quickSort(v_copy, 0, number);
                    time(&end);
                    cost = difftime(end, start);
                    cout << "Quicksort takes time: " << cost << endl;
                    break;

                case '6':
                    time(&start);
                    heapSort(v_copy);
                    time(&end);
                    cost = difftime(end, start);
                    cout << "Heapsort takes time: " << cost << endl;
                    break;

                case '7':
                    time(&start);
                    mergeSort(v_copy, 0, number);
                    time(&end);
                    cost = difftime(end, start);
                    cout << "Mergesort takes time: " << cost << endl;
                    break;

                case '8':
                    time(&start);
                    radixSort(v_copy);
                    time(&end);
                    cost = difftime(end, start);
                    cout << "Radixsort takes time: " << cost << endl;
                    break;
                default:
                    cout << "Incorrect input. Please re-enter your choice." << endl;
                    break;
            }
            cout << endl;
        }
    }
    return 0;
}