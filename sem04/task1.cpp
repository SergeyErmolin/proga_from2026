#include <iostream>

using std::cout;
using std::endl;

int main() {
    int N = 10'000'000;
    double *ptr;
    ptr = new double[N]; //new - берём память из кучи
    for (int i = 0; i < N; ++i)
    {
        ptr[i] = i;
    }
    for (int i = 0; i < N; i+= 10'000)
    {
       // cout << ptr[i] << endl;
    }
    cout << ptr << ' ' << &ptr << ' '<< &N << endl;
    delete[] ptr;
    ptr = new double;
    *ptr = 12.234;
    cout <<*ptr <<' ' << ptr[0] << ' ' << *(ptr + 0) << endl;
    delete ptr;
    cout << nullptr << ' ' << ptr << endl;
    ptr = nullptr;
    delete ptr;
    // for (int i = 0; i < 10; ++i)
    // {
    //     // ptr = new double[10]; (потеряно 720 байт)
    // }
    // //delete[] ptr;
    return 0;
}