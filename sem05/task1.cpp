#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <fstream>
#include <algorithm>

using namespace std;

int *create_random_array(int N, std::default_random_engine& rng) {
    int *array = new int[N];
    std::uniform_int_distribution<unsigned> dstr(0, 100'000);
    for (unsigned i = 0; i < N; ++i)
    {
        array[i] = dstr(rng);
    }
    return array;
}



int main() {
    
    unsigned seed = 1001;
    std::default_random_engine rng(seed);

    
    double intervals[] = {0.0, 1, static_cast<double>(100)};
    double weights[] = {1.0, 0.1, 0.0};
    std::piecewise_linear_distribution<double> dist(std::begin(intervals), std::end(intervals), std::begin(weights));
    
    int *random0 = create_random_array(100, rng);

    for (size_t i = 0; i < 100; i++) {
        cout << random0[static_cast<int>(dist(rng))] << ' ';
    }
    return 0;
}