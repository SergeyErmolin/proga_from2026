#include <iostream>
#include <algorithm> // для std::shuffle
#include <random>

using namespace std;

#define N 100
#define M 2


void readArray(int (&arr)[N]) {
    for ( int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
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
    std::random_device rd;
    std::mt19937 g(rd());

    int arr[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = i;
    }

    std::shuffle(arr, arr + N, g);

    printArray(arr);
}