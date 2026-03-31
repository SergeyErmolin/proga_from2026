#include <iostream>

using namespace std;

struct Node {
    int key = 0;
    Node* prev = nullptr;
    Node* next = nullptr;
};

struct List {
    Node* NIL = nullptr;
    Node* HEAD = nullptr;
    Node* TAIL = nullptr;
    size_t size = 0;
};

List* create_empty_list() {
    Node* new_kirpich = new Node;
    List* new_list = new List;
    new_list->NIL = new_kirpich;
    // new_list->HEAD = new_kirpich;
    // new_list->TAIL = new_kirpich;
    return new_list;
}

List* push_front(List* list_ptr, int new_key) {
    if (list_ptr == nullptr) return nullptr;
    Node* new_node = new Node;
    new_node->key = new_key;

    if (list_ptr->HEAD == nullptr) {
        list_ptr->HEAD = new_node;
        new_node->next=list_ptr->NIL;
        list_ptr->TAIL=new_node;
        new_node->prev=list_ptr->NIL;
        list_ptr->size += 1;
        return list_ptr;
    }

    Node* temp = list_ptr->HEAD;
    list_ptr->HEAD = new_node;
    new_node->prev=list_ptr->NIL;
    new_node->next=temp;
    temp->prev = new_node;
    list_ptr->size += 1;
    return list_ptr;
}

List* push_back(List* list_ptr, int new_key) {
    if (list_ptr == nullptr) return nullptr;
    Node* new_node = new Node;
    new_node->key = new_key;

    if (list_ptr->HEAD == nullptr) {
        list_ptr->HEAD = new_node;
        new_node->next=list_ptr->NIL;
        list_ptr->TAIL=new_node;
        new_node->prev=list_ptr->NIL;
        list_ptr->size += 1;
        return list_ptr;
    }

    Node* temp = list_ptr->TAIL;
    list_ptr->TAIL = new_node;
    new_node->next = list_ptr->NIL;
    new_node->prev=temp;
    temp->next = new_node;
    list_ptr->size += 1;
    return list_ptr;
}

List* insert_after(List* list_ptr, Node* prev_ptr, int new_key) {
    if (list_ptr == nullptr or prev_ptr == list_ptr->NIL) return list_ptr;
    // if (list_ptr->HEAD == nullptr) return list_ptr;
    ++(list_ptr->size);
    
    Node* new_node = new Node;
    new_node->key = new_key;
    // new_node->next = prev_ptr->next;
    new_node->next = list_ptr->NIL;
    new_node->prev = prev_ptr;
    prev_ptr->next = new_node;
    if (list_ptr->size == 2) {
        list_ptr->TAIL = new_node;
    }
    // if (new_node->next != nullptr) {
    //     new_node->next->prev = new_node;
    // }
	// if (prev_ptr == list_ptr->TAIL) {
    //     list_ptr->TAIL = new_node;
    // }
    return list_ptr;
}

void print_list(const List* list_ptr) {
    if (list_ptr == nullptr or list_ptr->HEAD == nullptr) {
        std::cout << std::endl;
        return;
    } else {
        Node* current = list_ptr->HEAD;
        while (current->next!=list_ptr->NIL) {
            std::cout << current->key << ' ';
            current = current->next;
        }
        std::cout << current->key << std::endl;
    }
}

int main() {
  List* list = create_empty_list();
  list = push_back(list, 0);
  list = insert_after(list, list->HEAD, 1);
  if ((list->HEAD->key == 0) and (list->TAIL->key == 1)) {
    cout << "OK" << endl;
  }
  delete list->HEAD;
  delete list->TAIL;
  delete list->NIL;
  delete list;
  return 0;
}