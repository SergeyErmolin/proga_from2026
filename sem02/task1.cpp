#include <iostream>
//forward declaration
int pref_inc(int&);
float pref_inc(float&);
int post_inc(int&);

using std::cout;
using std::endl;

float power_sqr(float);
int post_sqr(int)

int main() {
    int x = 1;
    cout << x << endl;
    cout << pref_inc(x) << endl;
    cout << x << endl;
    float y = 12.5;
    cout << y << endl;
    cout << pref_inc(y) << endl;
    double d = 12.5;
    cout << d << endl;
    cout << pref_inc(static_cast<float>(d)) << endl;
    return 0;
}

int power_sqr (int value) {
    return value*value;
}

float power_sqr (float value) {
    return (value*value);
}

// int value != int& value
float pref_inc(float& value) {
    // ++value;
    // value = value + 1;
    value += 1;
    return value;
}

int post_inc(int& value) {
    // ++value;
    // value = value + 1;
    int copy = value;
    value += 1;
    return copy;
}

