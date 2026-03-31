#include <iostream>
#include <random>

using std::cout;
using std::endl;

double *create_array(int N) {
    double *array = new double[N];
    return array;
}

double *create_random_array(int N, std::default_random_engine& rng) {
    double *array = new double[N];
    std::uniform_int_distribution<unsigned> dstr(0, 9);
    for (unsigned i = 0; i < N; ++i)
    {
        array[i] = dstr(rng);
    }
    return array;
}

int main() {
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    double *first = create_array(1'000);
    double *random0 = create_random_array(100, rng);
    double *random1 = create_random_array(100, rng);
    for (int i = 0; i < 100; ++i)
    {
        cout << i << ": " << (random0[i] == random1[i]) << endl;
    }
    return 0;
}