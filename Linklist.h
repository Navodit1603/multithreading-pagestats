#include<iostream>
#include<string>

using namespace std;

typedef string Element;

class List{

private:

    struct Node {
        Element data;
        Node* next;
        Node* prev;

        Node(Element x);  // Constructor for Node
    };
    
    int num_elements;  // Tracks the number of elements in the list
    Node* head;  // Pointer to the first element
    Node* tail;  // Pointer to the last element
    

public:
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

    void printList() const;  // Prints all elements in the list from head to tail

    // Manipulation procedures -------------------------------------------------

    // clear()
    // Deletes all elements in this List, setting it to the empty state.
    void clear();

    // insert()
    // Inserts a new element at the end of the List.
    void insert(Element x);
};
