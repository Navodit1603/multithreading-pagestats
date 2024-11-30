#include <iostream>
#include <fstream>
#include <string>
#include <cctype>  // For ispunct and isspace
#include "Fileread.h"

using namespace std;

// Helper function to remove punctuation from a word
string cleanWord(const string& word) {
    string cleaned;
    for (char ch : word) {
        if (!ispunct(ch)) {  // Remove punctuation
            cleaned += ch;
        }
    }
    return cleaned;
}

// Function to read sentences from a file and insert words into the linked list
void readFileToList(const string& filename, List& wordList) {
    ifstream file(filename);  // Open the file
    if (!file.is_open()) {
        cerr << "Error: Could not open the file " << filename << endl;
        return;
    }

    string word;
    // Read each word from the file
    while (file >> word) {
        string cleanedWord = cleanWord(word);  // Clean the word of punctuation
        if (!cleanedWord.empty()) {  // Only insert non-empty words
            wordList.insert(cleanedWord);
        }
    }

    file.close();  // Close the file
}
