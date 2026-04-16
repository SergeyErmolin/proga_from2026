#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;

void forward_step(unsigned arr[], unsigned const begin_ind, unsigned const end_ind) {
    unsigned temp;
    for (unsigned i = begin_ind; i < end_ind; ++i) {
        if (arr[i] > arr[i+1]) {
            temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
        }
    }
}

void backward_step(unsigned arr[], unsigned const begin_ind, unsigned const end_ind) {
    unsigned temp;
    for (unsigned i = end_ind; i > begin_ind; --i) {
        if (arr[i-1] > arr[i]) {
            temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
        }
    }
}

void shaker_sort(unsigned arr[], unsigned const begin_ind, unsigned const end_ind) {
    for (unsigned i = 0; i < end_ind - begin_ind; ++i) {
        if (i%2 == 0) {
            forward_step(arr, begin_ind + i/2, end_ind - i/2);
        } else {
            backward_step(arr, begin_ind + i/2, end_ind - 1 - i/2);
        }
    }
}

void forward_with_N_step(unsigned arr[], unsigned const begin_ind, unsigned const end_ind, unsigned const N) {
    unsigned temp;
    for (unsigned i = begin_ind; i < (end_ind+1-N); i+=N) {
        if (arr[i] > arr[i+N]) {
            temp = arr[i+N];
            arr[i+N] = arr[i];
            arr[i] = temp;
        }
    }
}

void forward_with_N_step_and_counter(unsigned arr[], unsigned const begin_ind, unsigned const end_ind, unsigned const N, unsigned& counter) {
    unsigned temp;
    for (unsigned i = begin_ind; i < (end_ind+1-N); i+=N) {
        if (arr[i] > arr[i+N]) {
            temp = arr[i+N];
            arr[i+N] = arr[i];
            arr[i] = temp;
            ++counter;
        }
    }
}

unsigned comb_sort_and_counter(unsigned arr[], unsigned const begin_ind, unsigned const end_ind) {
    unsigned step = 1 + (end_ind - begin_ind)/2;
    bool toggle = true;
    unsigned temp;
    unsigned counter=0;
    while (step > 1) {
        forward_with_N_step_and_counter(arr, begin_ind, end_ind, step, counter);
        step /= 2;
    }
    while (toggle) {
        toggle = false;
        for (unsigned i = begin_ind; i < end_ind; ++i) {
            if (arr[i] > arr[i+1]) {
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                toggle = true;
                ++counter;
            }
        }
    }
    return counter;
}

void comb_sort(unsigned arr[], unsigned const begin_ind, unsigned const end_ind) {
    unsigned step = 1 + (end_ind - begin_ind)/2;
    bool toggle = true;
    unsigned temp;
    while (step > 1) {
        forward_with_N_step(arr, begin_ind, end_ind, step);
        step /= 2;
    }
    while (toggle) {
        toggle = false;
        for (unsigned i = begin_ind; i < end_ind; ++i) {
            if (arr[i] > arr[i+1]) {
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                toggle = true;
            }
        }
    }
}

void fill_array(unsigned* arr, unsigned len) {
    for (int i = 0; i < len; ++i) {
        cin >> arr[i];
    }
}

void print_array(unsigned* arr, unsigned len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << ' ';
    }
}

unsigned *create_random_array_with_span(std::default_random_engine& rng, unsigned N, unsigned span) {
    unsigned *array = new unsigned[N];
    std::uniform_int_distribution<unsigned> dstr(0, span);
    for (unsigned i = 0; i < N; ++i) {
        array[i] = dstr(rng);
    }
    return array;
}

void fill_random_array_with_span(std::default_random_engine& rng, unsigned N, unsigned* arr, unsigned span) {
    std::uniform_int_distribution<unsigned> dstr(0, span);
    for (unsigned i = 0; i < N; ++i) {
        arr[i] = dstr(rng);
    }
}

int64_t schitaem_vrema_sort_defined_length(unsigned length, std::function<void(unsigned*, unsigned const, unsigned const)> func, std::default_random_engine& rng) {
    
    // time for fill_random_array_with_span()
    auto begin = std :: chrono :: steady_clock ::now();
    unsigned* test_array = new unsigned[length];
    for (unsigned cnt = 300; cnt != 0;--cnt) {
        fill_random_array_with_span(rng, length, test_array, length);
    }
    auto end = std :: chrono :: steady_clock ::now();
    auto time_creating = std :: chrono :: duration_cast<std :: chrono :: milliseconds >(end-begin);
    
    begin = std :: chrono :: steady_clock ::now();
    for (unsigned cnt = 300; cnt != 0;--cnt) {
        fill_random_array_with_span(rng, length, test_array, length);
        func(test_array, 0, length-1);
    }
    delete[] test_array;
    end = std :: chrono :: steady_clock ::now();
    auto time_all = std :: chrono :: duration_cast<std :: chrono :: milliseconds >(end-begin);
    
    return time_all.count() - time_creating.count();
}

int64_t schitaem_perestonovki_sort_defined_length(unsigned length, std::function<unsigned(unsigned*, unsigned const, unsigned const)> func, std::default_random_engine& rng) {
    int64_t counter = 0;
    unsigned* test_array = new unsigned[length];

    for (unsigned cnt = 30; cnt != 0;--cnt) {
        fill_random_array_with_span(rng, length, test_array, length);
        counter += func(test_array, 0, length-1);
    }
    delete[] test_array;
    
    return counter/30;
}

/*  //SORT TEST
int main() {
    unsigned seed = 1001;
    std::default_random_engine rng(seed);

    std::ofstream outFile("test0.txt");

    outFile << "time" << ',' << "length" << '\n';

    for (int i = 1000; i <= 15000; i+=1000) {
        outFile << schitaem_vrema_sort_defined_length(i, comb_sort, rng) << ',' << i << '\n';
    }

    return 0;
} */

  //reverse TEST
int main() {
    unsigned seed = 1001;
    std::default_random_engine rng(seed);

    std::ofstream outFile("test0.txt");

    outFile << "time" << ',' << "length" << '\n';

    for (int i = 1000; i <= 15000; i+=1000) {
        outFile << schitaem_perestonovki_sort_defined_length(i, comb_sort_and_counter, rng) << ',' << i << '\n';
    }

    return 0;
}

/* FORWARD, BACKWARD STEP TEST
int main() {
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    bool clik = true;
    for (unsigned i = 100; i <= 102400; i *= 2) {
        unsigned* test = create_random_array_with_span(rng, i, i);
        forward_step(test, 0, i-1);
        backward_step(test, 0, i-1);
        unsigned minim = *std::min_element(test, test + i);
        unsigned maxim = *std::max_element(test, test + i);
        if ( minim != *test or maxim != *(test +i -1) ) {
            clik = false;
        }
        delete[] test;
    }
    cout << clik;
    return 0;
} */

/* //test code0
int main() {
    unsigned n;
    cin >> n;
    unsigned* arr = new unsigned[n];
    fill_array(arr, n);
    cout << endl;
    comb_sort(arr, 0, n-1);
    print_array(arr, n);
    delete[] arr;
    return 0;
} */