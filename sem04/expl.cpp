#include <iostream>

using std::cout;
using std::endl;

int main() {
    int N = 1'000'000, M = 1234;
    double pi = 3.14, e =2.;
    int *ptr_N = &N, *ptr_M = &M;
    double *ptr_pi = &pi;

    cout << &N << ' ' << ptr_N << ' ' << N << endl;
    cout << &M << ' ' << M << endl;
    cout << &pi << ' ' << pi << endl;
    cout << &e << ' ' << e << endl;
    cout << ptr_N - ptr_M << endl;
    //cout << ptr_e - ptr_N << endl;

    //cout << ptr_N + ptr_M << endl;
    //cout << ptr_M + 1 << endl;
    cout << ptr_pi - 1 /* e */ << endl;
    *(ptr_pi - 1) = 3.141592; // e -> 3.141592
    *(ptr_pi - 100) = 3.141592;
    cout << ptr_pi - 1 << ' ' << *(ptr_pi) << endl;
    return 0;
}