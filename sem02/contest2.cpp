#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long int pow(long long int x, int n) {
    long long int p = 1;
    for (int i = 0; i < n; ++i)
    {
        p *= x;
    }
    return p;
}

int logbase(long long int x, int base) {
    long long int c = 1;
    int p = 0;
    while (c <= x)
    {
        ++p;
        c *= base;
    }
    return p;
}

long long int socrashenie(long long int x, int base, int rasr) {
    return (x - pow(base, rasr));
}

int rasryad(long long int x, int base, int rasr) {
    for (int i = 1; i <= base; ++i)
    {
        if (x - i*pow(base, rasr) < 0)
        {
            return (i-1);
        }
    }
    return 989;
}

int main() {
    long long int n;
    int base;
    int rasrnow;
    cin >> n >> base;
    string itog = "";
    int base_len = logbase(n, base);
    
    for (int i = base_len-1; i >= 0; --i)
    {
        rasrnow = rasryad(n, base, i);
        itog = itog + to_string(rasrnow);

        n -= rasrnow*pow(base, i);
    }
    cout << itog;

    return 0;
}