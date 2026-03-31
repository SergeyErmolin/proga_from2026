#include <iostream>

using std::cout;
using std::endl;

void print(int value) {
    cout << ' ' << value << ' ' << endl;
}

int main() {
    int long_name_of_my_love; //= 3.141512009;
    int& ref = long_name_of_my_love;
    cout << ref << ' ' << long_name_of_my_love << endl;
    ++ref;
    cout << ref << ' ' << long_name_of_my_love << endl;
    ++long_name_of_my_love;
    cout << ref << ' ' << long_name_of_my_love << endl;
    print(ref);
    return 0;
}