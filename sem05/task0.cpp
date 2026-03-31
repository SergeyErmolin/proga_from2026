#include<iostream>

using namespace std;

struct Velocity {
    double v_x = 0.0;
    double v_y = 0.0;
};


unsigned fib(unsigned N) {
    if (N < 2) {
        return 1;
    }
    return fib(N-1) + fib(N-2);
}

void quicksort(int* arr, int l_idx, int r_idx, int size) {
    int opr = arr[(l_idx + r_idx)/2];
    while (l_idx < r_idx) {
        while (arr[l_idx] < opr) ++l_idx;
        while (arr[r_idx] > opr) --r_idx;
        if (l_idx < r_idx) swap(arr[l_idx], arr[r_idx]);
    }
    quicksort(arr, 0, l_idx, l_idx+1);
    quicksort(arr, l_idx + 1, size - 1, size - l_idx-1);
}

int main() {
    // cout << fib(44) << endl;
    // unsigned dp[44] = {0};
    // dp[0] = 1;
    // dp[1] = 1;
    // for (size_t i = 2; i < 44; ++i)
    // {
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }

    // Velosity of n particles
    double *v_x = new double[100];
    double *v_y = new double[100];
    double *v = new double[1000 * 2];
    // v[idx_particle][idx_dimention]
    double **v2d = new double*[1000];
    for (size_t idx = 0; idx < 1000; ++idx) {
        v2d[idx] = new double[2];
    }
    delete[] v_x;
    delete[] v_y;
    for (size_t i = 0; i < 1000; ++i) {
        delete[] v2d;
    }
    delete[] v;
    Velocity velocity;
    velocity.v_x = 1.23456;
    velocity.v_y = 1.23456;
    Velocity *arr = new Velocity[100];
    arr[10].v_x;

    Velocity *dp_velocity = new Velocity;
    dp_velocity->v_x;
    (*dp_velocity).v_x;
    delete dp_velocity;

    return 0;
}