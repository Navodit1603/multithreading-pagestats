#include <iostream>
#include "Linklist.h"

using namespace std;

int main() {
    // Create a new list
    List myList;

    // Check if the list is initially empty
    cout << "Initial length of list: " << myList.length() << endl;

    // Insert elements into the list
    myList.insert("Apple");
    myList.insert("Banana");
    myList.insert("Cherry");

    // Check the length after insertion
    cout << "Length after inserting 3 elements: " << myList.length() << endl;

    // Access and display the front and back elements
    cout << "Front element: " << myList.front()->data << endl;  // Should print "Apple"
    cout << "Back element: " << myList.back()->data << endl;    // Should print "Cherry"

    // Insert another element
    myList.insert("Date");
    cout << "Length after inserting another element: " << myList.length() << endl;
    cout << "New back element: " << myList.back()->data << endl;  // Should print "Date"

    myList.printList();

    // Clear the list and check its length
    myList.clear();
    cout << "Length after clearing the list: " << myList.length() << endl;

    // Check front and back after clearing (should not access invalid memory)
    if (myList.front() == nullptr) {
        cout << "List is empty, no front element." << endl;
    }
    if (myList.back() == nullptr) {
        cout << "List is empty, no back element." << endl;
    }

    return 0;
}
