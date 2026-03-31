#include <iostream>
#include <string>

using namespace std;

enum MathOperators {minus = 45, plus = 43};

int main() {
    string input;
    while (cin >> input) {
        cout << "someone put: " << input << endl;
        if (input == "-" or input == "+") {
            cout << "it is a math operator";
            switch (static_cast<MathOperators>(input)) {
            case MathOperators::minus:
                cout << " ho-ho it is a minus";
                break;
            case MathOperators::plus:
                cout << " ho-ho it a plus";
                break;
            default:
                break;
            }
        }
    }
    
}