#include <iostream>
#include <string>
#include <chrono>
#include <algorithm> // std::shuffle
#include <random>

using namespace std;

#define N 100000

string line_find_idx(int arr[N], int elm) {
    for ( int i = 0; i < N; ++i)
    {
        if (arr[i] == elm)
        {
            return to_string(i);
        }
    }
    return "not found";
}

string binar_find_idx(int (&arr)[N], int elm) {
    int l_idx = 0, r_idx = N-1, c;
    while (l_idx < r_idx)
    {
        c = l_idx + (r_idx - l_idx + 1)/2;
        if (elm >= arr[c])
        {
            l_idx = c;
        } else {
            r_idx = c-1;
        }
    }
    if (arr[l_idx] == elm)
    {
        return to_string(l_idx);
    } else {
        return "not found";
    }
}

void printArray(int (&arr)[N]) {
    for ( int i = 0; i < N-1; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << arr[N-1] << std::endl;
}

int main() {
    // sozda`em spisok
    std::random_device rd;
    std::mt19937 g(rd());

    int arr[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = i;
    }

    std::shuffle(arr, arr + N, g);

    //printArray(arr);

    // schitaem vrema
    auto begin = std :: chrono :: steady_clock ::now();
    for (unsigned cnt = 100000; cnt != 0;--cnt) {
        line_find_idx(arr, 89); // suda funcCiu
    }
    auto end = std :: chrono :: steady_clock ::now();
    auto time_span = std :: chrono :: duration_cast<std :: chrono :: milliseconds >(end- begin );
    std :: cout << "\n\n";
    std :: cout << time_span.count() << std :: endl;

    return 0;
}