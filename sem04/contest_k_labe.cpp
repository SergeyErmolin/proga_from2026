#include <iostream>
#include <fstream>

using namespace std;

int* give_N_elements(unsigned int N, int value) {
    int *array = new int[N];
    for (unsigned i = 0; i < N; ++i)
    {
        array[i] = value;
    }
    return array;
}

int* take_N_elements(int* ptr) {
    delete[] ptr;
    return nullptr;
}

void swap_arr(int*& ptr0, int*& ptr1) {
    int* ptr_tpr = ptr1;
    ptr1 = ptr0;
    ptr0 = ptr_tpr;
}

void reshape_arr(int*& ptr, unsigned int N, unsigned int M) {
    int* arr_M = new int[M];

    if (N < M){
        for (unsigned int i = 0; i < N; i++)
        {
            arr_M[i] = *(ptr + i);
        }
        for (unsigned int i = N; i < M; ++i)
        {
            arr_M[i] = 0;
        }
    } else {
        for (unsigned int i = 0; i < M; i++)
        {
            arr_M[i] = *(ptr + i);
        }
    }
    delete[] ptr;
    ptr = arr_M;
}

void merge(int*& res, int*& ptr0, unsigned int N, int*& ptr1, unsigned int M) {
    delete[] res;
    int* ptr_temp = new int[N + M];
    res = ptr_temp;
    for (unsigned int i = 0; i < N; ++i)
    {
        res[i] = ptr0[i];
    }
    for (unsigned int i = 0; i < M; i++)
    {
        res[N+i] = ptr1[i];
    }
}

int main() {
    int start, stop, step, delt;
    cin >> start >> stop >> step;
    if (step < 0) {
        int a = start;
        start = stop;
        stop = a;
    }
    delt = (stop - start)/step;

    std::ofstream outFile("output.txt");


    for (int i = 0; i <= delt; ++i)
    {
        outFile << i << ':' << start + i*step << '\t';
    }
    return 0;
}