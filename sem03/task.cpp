#include <iostream>

int main() {
    double arr1[] = {1,2,3}, arr0[] = {-1,-2,-3,-4};
    double val = 0.0;
    // arr0 = arr1;
    // arr1 = arr0;
    std::cout << typeid(arr0).name() << '\n';
    std::cout << typeid(arr1).name() << '\n';
    std::cout << arr0 << ' ' << *arr0 << std::endl;
    // std::cout << arr0 + 1<< ' ' << *(arr0 + 1) << std::endl;
    std::cout << arr1<< ' ' << *(arr1) << std::endl;
    std::cout << arr1 + 5<< ' ' << *(arr1 + 5) << std::endl;
    //std::cout << arr1 << std::endl;
    //std::cout << arr0 - arr1 << std::endl;
    for (int idx = 0; idx < 4; ++idx) {
        // No bound check!!!
        std::cout << arr0[idx] << ' ' << arr1[idx] << std::endl;
    }
    
    return 0;
}