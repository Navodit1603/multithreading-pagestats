#include <iostream>
#include <fstream>
#include <string>
#include "Linklist.h"
#include "Fileread.h"

using namespace std;

int regular(string filename){
    List wordList;
    readFileToList(filename, wordList);
    List::Node* current = wordList.front();
    float word_count = 0.0;
    float characters = 0.0;
    int longest_word_length = 0;
    string longest_word = "";
    for(int i = 0; i < wordList.length(); i++){
        word_count++;
        characters = characters + current->data.length();
        if(current->data.length() > longest_word_length){
            longest_word_length = current->data.length();
            longest_word = current->data;
        }
        current = current->next;
    }
    cout << "Number of Words: " << word_count << endl;
    cout << "Average Word Length: " << characters/word_count << endl;
    cout << "Longest Word: " << longest_word << endl;
    cout << "Longest Word Length: " << longest_word_length << endl;

    return 0;
}


int main(int argc, char* argv[]) {
    if(argc != 2){
        throw std::invalid_argument("Not enough arguments provided to program");
    }
    string filename = argv[1];
    regular(filename);

    List wordList;
    int numThreads = 4;  // Adjust based on system capabilities

    threadReadFileToList(filename, wordList, numThreads);

    wordList.printList();  // Assuming List has a print function

    return 0;
}