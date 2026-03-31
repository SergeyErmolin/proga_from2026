#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void heapify(int *arr, const int size, int idx_root) {
    int idx_largest = idx_root;

    int idx_l = idx_root * 2 + 1;
    if (idx_l < size and arr[idx_largest] < arr[idx_l]) {
        idx_largest = idx_l;
    }

    int idx_r = idx_root * 2 + 2;
    if (idx_r < size and arr[idx_largest] < arr[idx_r]) {
        idx_largest = idx_r;
    }
    
    if (idx_largest != idx_root) {
        swap(arr[idx_largest], arr[idx_root]);

        heapify(arr, size, idx_largest);
    }
}

void heapSort(int* arr, const int size) {
    for (int i = size -1 ; i>=0; --i) {
        heapify(arr, size, i);
    }
    
    for (int idx = size-1; idx >=0; --idx) {
        swap(arr[0], arr[idx]);
        heapify(arr, idx, 0);
    }
}

int main() {
    int arr[] = {7, 3, 1, 3, 7, 6, 4, 7, 9, 0};
    const int size = sizeof(arr) / sizeof(arr[0]);
    
}