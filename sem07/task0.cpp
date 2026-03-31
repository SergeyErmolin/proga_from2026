#include <iostream>

using namespace std;

struct Node {
    int field_int;
    int field_int_secondary;
    double field_double;
};

struct EmptyNode {};

int main() {
    Node my_favorate_node = Node();
    Node* node_array = new Node[12];
    cout << sizeof(char) << endl;
    cout << sizeof(EmptyNode) << endl;
    cout << sizeof(Node) << endl;
    cout << sizeof(my_favorate_node) << endl;
    cout << my_favorate_node.field_int << endl;
    delete[] node_array;
    return 0;
}
