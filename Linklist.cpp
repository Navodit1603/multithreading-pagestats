#include<iostream>
#include<string>
#include<stdexcept>

#include "Linklist.h"

// Node constructor
List::Node::Node(Element x){
    data = x;
    next = nullptr;
    prev = nullptr;
}

// List constructor
List::List(){
    num_elements = 0;
    head = nullptr;
    tail = nullptr;
}

// List destructor
List::~List(){
    clear();  // Reuse the clear function to clean up all nodes
}

// Returns the number of elements in the list
int List::length() const {
    return num_elements;
}

// Returns the first node in the list (head)
List::Node* List::front() const {
    if(num_elements != 0) {
        return head;
    }
    return nullptr;
}

// Returns the last node in the list (tail)
List::Node* List::back() const {
    if(num_elements != 0) {
        return tail;
    }
    return nullptr;
}

string List::get(Node* node){
    if(node != nullptr){
        return node->data;
    }
    else{
        return "";
    }
}

void List::printList() const {
    Node* current = head;
    if (current == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "List contents: " << endl;
    while (current != nullptr) {
        cout << current->data << endl;  // Print the data of the current node
        current = current->next;  // Move to the next node
    }
    cout << endl;
}

// Deletes all nodes in the list and resets the list to empty
void List::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    num_elements = 0;
}

// Inserts a new element at the end of the list
void List::insert(Element x) {
    Node* newNode = new Node(x);
    if (num_elements == 0) {
        // If the list is empty, the new node becomes both the head and tail
        head = newNode;
        tail = newNode;
    } else {
        // Otherwise, link the new node to the current tail
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    num_elements++;
}

// Merge list y at the end of list x
void List::merge(List& x, List& y) {
    if (y.head == nullptr) return; // If y is empty, do nothing
    if (x.head == nullptr) { // If x is empty, just assign y to x
        x.head = y.head;
        x.tail = y.tail;
    } else {
        x.tail->next = y.head;
        y.head->prev = x.tail;
        x.tail = y.tail;
    }
    x.num_elements += y.num_elements; // Update element count

    // Clear y
    y.head = nullptr;
    y.tail = nullptr;
    y.num_elements = 0;
}
