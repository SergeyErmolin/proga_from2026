#include <iostream>

using std::cout;
using std::endl;

struct Node {
    int key = 0;
    Node* next = nullptr;
};

void push_front(Node*& head_ref, int new_key) {
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->next = head_ref;
    head_ref = new_node;
    return;
}

void push_back(Node*& head_ref, int new_key) {
    Node* current = head_ref;
    Node* new_node = new Node;
    new_node->key = new_key;
    if (current == nullptr) {
        head_ref = new_node;
        return;
    } else {
        while (current->next != nullptr) {
            current = current->next;
        }
    }
    current->next = new_node;
    return;
}

void insert_after(Node*& prev_ref, int new_key) {
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->next = prev_ref->next;
    prev_ref->next = new_node;
}

void destroy_list(Node*& head_ref) {
    Node* current = head_ref;
    Node* tmp = nullptr;
    while (current != nullptr) {
        tmp = current->next;
        delete current;
        current = tmp;
    }
    head_ref = nullptr;
    return;
}

void print_list(Node* head_ref) {
    if (head_ref == nullptr) {
        std::cout << std::endl;
        return;
    } else {
        while (head_ref->next!=nullptr) {
            std::cout << head_ref->key << ' ';
            head_ref = head_ref->next;
        }
        std::cout << head_ref->key << std::endl;
    }
}

Node* find(Node* head_ref, int key) {
    while (head_ref!=nullptr) {
        if (head_ref->key == key) {
            return head_ref;
        }
        head_ref = head_ref->next;
    }
    return nullptr;
}

void remove_key(Node*& head_ref, int key) {
    if (head_ref == nullptr) return;
    Node* head = head_ref;
    Node* temp;
    if (head_ref->key == key) {
        temp = head_ref->next;
        delete head_ref;
        head_ref = temp;
        return;
    }
    while (head->next!=nullptr) {
        if (head->next->key == key) {
            temp = head->next;
            head->next = head->next->next;
            delete temp;
            return;
        }
        head = head->next;
    }
    if (head->key == key) {
        head = nullptr;
    }
    return;
}

Node* read_list(Node*& head) {
    int temp = -1;
    while (temp != 0) {
        std::cin >> temp;
        push_back(head, temp);
    }
    return head;
}

Node* reverse(Node* head) {
    if (head == nullptr or head->next == nullptr) return head;
    Node* current = head;
    Node* temp = current->next;
    Node* pred = nullptr;
    while (temp != nullptr) {
        current->next = pred;
        pred = current;
        current = temp;
        temp = temp->next;
    }
    current->next = pred;
    return current;
}

int main() {
  Node* head = nullptr;
  head = read_list(head);
  head = reverse(head);
  print_list(head);
  destroy_list(head);
  return 0;
}