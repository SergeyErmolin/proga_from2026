#include <iostream>

int c = 0;

int main() {
    int x = 0;
    int idx = 1;
    for (int idx = 0; idx != 10; ++idx) {
        std::cout << idx << ' ';
    }
    
    while (true) {
        ++idx;
        if (idx>100) {
            break;
        }
    }

    idx *= 2;

    {
        int idx = 7;
    }
    int c = 213
    std::cout << std::endl;
    std::cout << c << std::endl;
    return 0;
}