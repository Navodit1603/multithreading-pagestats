#include<iostream>
#include<string>


#ifndef LINKLIST_H
#define LINKLIST_H

using namespace std;

typedef string Element;

class List{

public:
    
    struct Node {
        Element data;
        Node* next;
        Node* prev;

        Node(Element x);  // Constructor for Node
    };

    List();   // Constructor for List

    ~List();  // Destructor for List

    // Access functions --------------------------------------------------------

    // length()
    // Returns the number of elements in this List.
    int length() const;

    // front()
    // Returns the first Node in this List.
    Node* front() const;

    // back()
    // Returns the last Node in this List.
    Node* back() const;

    string get(Node* node);

    void printList() const;  // Prints all elements in the list from head to tail

    // Manipulation procedures -------------------------------------------------

    // clear()
    // Deletes all elements in this List, setting it to the empty state.
    void clear();

    // insert()
    // Inserts a new element at the end of the List.
    void insert(Element x);

    // merge()
    // Merges a list y at the end of the list x.
    void merge(List& x, List& y);

private:

    
    int num_elements;  // Tracks the number of elements in the list
    Node* head;  // Pointer to the first element
    Node* tail;  // Pointer to the last element
    
};

#endif // LINKLIST_H