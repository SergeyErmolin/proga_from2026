#include <iostream>
using namespace std;
// #include <cmath>
// #include <string>

// using namespace std;

// int main() {
//     long int a, toggle = 0, len, c=1;
//     cin >> a;
//     std::string s = std::to_string(a);
//     len = s.length();
//     if (len!=1) {


//         for (int idx=len; idx > 1; --idx) {
//             if ( s[idx-1] != s[(len)-idx]) {
//                 c = 0;
//             }
//             toggle = c;
//         }

//     } else {
//         toggle = 1;
//     }

//     cout << toggle;
//     return 0;
// }

// /*
// #include <iostream>
// #include <cmath>
// #include <string>

// using namespace std;

// int main() {
//     long int a, toggle = 0, len, c=1;
//     cin >> a;
//     std::string s = std::to_string(a);
    
//     if (a!=0) {

//         len = s.length();

//         if (len%2==0) {
//             for (int idx=len/2; idx > 1; --idx) {
//                 if ( s[idx-1] != s[(len)-idx]) {
//                     c = 0;
//                 }
//                 toggle = c;
//             }
//         } else {
//             for (int idx=(len-1)/2; idx > 1; --idx) {
//                 if ( s[idx-1] != s[(len)-idx]) {
//                     c = 0;
//                 }
//                 toggle = c;
//             }
//         }

//     } else {
//         toggle = 1;
//     }

//     cout << toggle;
//     return 0;
// }*/

int gcd(int a, int b){
    a %= b;
    return a ? gcd(b, a) : b;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
}