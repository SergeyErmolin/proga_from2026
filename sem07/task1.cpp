#include <iostream>

using namespace std;

struct Node {
    int field;
    Node* next;
};

struct List {
    Node* HEAD;
    Node* TAIL;
    Node* NILL;
};

// List* create_list() {
//     Lidt* list = new List();
//     list->HEAD
// }
/*
void push(Node*& HEAD, int value) {
    if (HEAD == nullptr) {
        HEAD = new Node();
        HEAD->field = value;
        HEAD->next = nullptr;
        return;
    } else {
        Node *new_HEAD = new Node();
        new_HEAD->field = value;
        new_HEAD->next = HEAD;
        HEAD = new_HEAD;
        return;
    }
}
*/

void push(Node*& HEAD, int value) {
    if (HEAD == nullptr) {
        HEAD = new Node();
        HEAD->field = value;
        HEAD->next = nullptr;
        return;
    } else {
        Node *new_HEAD = new Node();
        new_HEAD->field = value;
        new_HEAD->next = HEAD;
        HEAD = new_HEAD;
        return;
    }
}

int main() {
    Node* HEAD = nullptr;
    push(HEAD, 0);
    push(HEAD, -1);
    push(HEAD, -2);
    for (Node* current = HEAD; current!=nullptr; current->next) {
        cout << current->field << endl;
    }
    
    //cout << HEAD->field <<endl;
    return 0;
}