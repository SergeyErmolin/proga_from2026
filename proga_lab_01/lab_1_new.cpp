#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <fstream>
#include <algorithm>

using namespace std;

//#define N 100000

int* give_N_elements(unsigned int N, int value) {
    int *array = new int[N];
    for (unsigned i = 0; i < N; ++i)
    {
        array[i] = value;
    }
    return array;
}

int *create_random_array(int N, std::default_random_engine& rng) {
    int *array = new int[N];
    std::uniform_int_distribution<unsigned> dstr(0, 100'000'000);
    for (unsigned i = 0; i < N; ++i)
    {
        array[i] = dstr(rng);
    }
    return array;
}

string line_find_idx(int N, int elm, int* ptr) {
    for (int i = 0; i < N; ++i)
    {
        if (ptr[i] == elm)
        {
            return to_string(i);
        }
    }
    return "not found";
}

string binar_find_idx(int N, int elm, int* ptr) {
    int l_idx = 0, r_idx = N-1, c;
    while (l_idx < r_idx)
    {
        c = l_idx + (r_idx - l_idx + 1)/2;
        if (elm >= ptr[c])
        {
            l_idx = c;
        } else {
            r_idx = c-1;
        }
    }
    if (ptr[l_idx] == elm)
    {
        return to_string(l_idx);
    } else {
        return "not found";
    }
}

string sqr_find_sum_to_match(int N, int elm, int* ptr) {
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j)
        {
            if (ptr[i] + ptr[j] == elm) {
                    return to_string(i) + " and " + to_string(j);
            }
        }
    }
    return "not found";
}

string lin_find_sum_to_match(int N, int elm, int* ptr) {
    int left = 0, right = N-1;
    while (left < right) {
        if (ptr[right]+ptr[left] < elm) {
            ++left;
        } else if (ptr[right]+ptr[left] == elm) {
            return to_string(left) + " and " + to_string(right);
        } else {
            --right;
        }
    }
    return "no such pair";
}

string line_A_find_idx(int N, int elm, int*& ptr) {
    for (int i = 0; i < N; ++i)
    {
        if (ptr[i] == elm)
        {
            ptr[i] = ptr[0];
            ptr[0] = elm;
            return to_string(i);
        }
    }
    return "not found";
}

string line_B_find_idx(int N, int elm, int*& ptr) {
    for (int i = 0; i < N; ++i)
    {
        if (ptr[i] == elm)
        {
            if (i!=0) {
                ptr[i] = ptr[i-1];
                ptr[i-1] = elm;
            }
            return to_string(i);
        }
    }
    return "not found";
}

string line_C_find_idx(int N, int elm, int*& ptr, int*& schet) {
    int temp;
    for (int i = 0; i < N; ++i)
    {
        if (ptr[i] == elm) {
            if (i!=0) {
                if ((1 + schet[i]) > schet[i-1]) {
                    schet[i] += 1;
                    ptr[i] = ptr[i-1];
                    ptr[i-1] = elm;
                    temp = schet[i];
                    schet[i] = schet[i-1];
                    schet[i-1] = temp;
                }
            }
            return to_string(i);
        }
    }
    return "not found";
}

int64_t schitaem_vrema_bad(int length, int find_el, int*& random_arr, int*& schet) {
    auto begin = std :: chrono :: steady_clock ::now();
    for (unsigned cnt = 10000; cnt != 0;--cnt) {
        lin_find_sum_to_match(length, find_el, random_arr); // suda funcCiu
    }
    auto end = std :: chrono :: steady_clock ::now();
    auto time_span = std :: chrono :: duration_cast<std :: chrono :: microseconds >(end-begin);

    return time_span.count();
}

int64_t schitaem_vrema_medium(int length, std::default_random_engine& rng, int*& random_arr, int*& schet) {
    std::uniform_int_distribution<unsigned> element_dstr(0, length);
    auto begin = std :: chrono :: steady_clock ::now();
    for (unsigned cnt = 100000; cnt != 0;--cnt) {
        //line_C_find_idx(length, random_arr[element_dstr(rng)], random_arr, schet); // suda funcCiu
        sqr_find_sum_to_match(length, random_arr[element_dstr(rng)] + random_arr[element_dstr(rng)], random_arr);
    }
    auto end = std :: chrono :: steady_clock ::now();
    auto time_span = std :: chrono :: duration_cast<std :: chrono :: microseconds >(end-begin);
    return time_span.count();
}

int64_t schitaem_vrema_ABC(int length, std::default_random_engine& rng, int*& random_arr, int*& schet) {
    int* karta = new int[length];
    for (int i = 0; i < length; ++i) {
        karta[i] = random_arr[i];
    }
    
    double intervals[] = {0.0, static_cast<double>(length)};
    double weights[] = {1.0, 0.0};
    std::piecewise_linear_distribution<double> dist(std::begin(intervals), std::end(intervals), std::begin(weights));

    auto begin = std :: chrono :: steady_clock ::now();
    for (unsigned cnt = 100000; cnt != 0;--cnt) {
        static_cast<int>(dist(rng));
    }
    auto end = std :: chrono :: steady_clock ::now();
    auto time_form = std :: chrono :: duration_cast<std :: chrono :: microseconds >(end-begin);
    
    begin = std :: chrono :: steady_clock ::now();
    for (unsigned cnt = 100000; cnt != 0;--cnt) {
        line_find_idx(length,karta[static_cast<int>(dist(rng))], random_arr); //   ,schet   suda funcCiu
    }
    end = std :: chrono :: steady_clock ::now();
    auto time_span = std :: chrono :: duration_cast<std :: chrono :: microseconds >(end-begin);
    
    delete[] karta;
    return time_span.count() - time_form.count();
}

int main() {

    unsigned seed = 1001;
    std::default_random_engine rng(seed);

    int find_el = -1, a = 0;

    std::ofstream outFile("lin_1to0.txt");

    outFile << "time" << ',' << "length" << '\n';

    for (int i = 500; i < 8'000'000; i*=2) {
        int *random0 = create_random_array(i, rng);
        int *schetchik = give_N_elements(i, 0);
        //std::sort(random0, random0 + i);
        outFile << schitaem_vrema_ABC(i, rng, random0, schetchik) << ',' << i << '\n';
        delete[] random0;
        delete[] schetchik;
    }

/*   dlya bistrih
    for (int i = 500; i < 2'000'000; i*=2) {
        a = 0;
        for (int j = 0; j < 100; ++j) {
            int *random0 = create_random_array(i, rng);
            std::sort(random0, random0 + i);
            a += schitaem_vrema(i, find_el, random0);
            delete[] random0;
        }
        outFile << a/100 << ',' << i << '\n';
        //delete[] random0;
    }
*/

    return 0;
}