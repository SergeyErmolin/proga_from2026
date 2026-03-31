#include <iostream>

int main() {
    int x = 0, y = 0;
    float z = 0.0f;
    x = 10 + 12;
    y = x * 5;
    //z = y;
    //z /= 7;
    z = y / 7.0f;
    std::cin >> z >> x >> y;
    for (int idx = 1; idx < 5; ++idx) {
        z *= 1;
    }
    std::cout << "Hello! " << x << " " << y << ' ' << z << std::endl;
    std::cout << z << ' ' << ++z << ' ' << z++ << ' ' << z << std::endl;
    x = y % 7;
    std::cout << x << std::endl;
    bool flag = true;
    bool flag_alt = false;
    if ((x < y) and (y < 10)) {
        std::cout << "X menshe Y";
    } else {
        std::cout << "Y menshe X";
    } 
    while (x > 0) {
        ++x;
    }
    std::cout << --x << std::endl;

    return 0;
}