#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
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


// ---------------------------------Thread Functions--------------------------------------------

mutex listMutex;  // Mutex to protect the shared linked list

// Function for each thread to process a specific chunk of the file
void readChunk(const string& filename, streampos start, streampos end, List& threadList) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    file.seekg(start);  // Move to the assigned chunk start

    // Ensure we start at a new word
    if (start != 0) {
        string temp;
        file >> temp;  // Move to the next full word
    }

    string word;
    while (file.tellg() < end && file >> word) {
        string cleanedWord = cleanWord(word);
        if (!cleanedWord.empty()) {
            threadList.insert(cleanedWord);  // Insert into thread-local list
        }
    }
}

// Multi-threaded file reading function
void threadReadFileToList(const string& filename, List& wordList, int numThreads) {
    ifstream file(filename, ios::ate | ios::binary);  // Open file in binary mode
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    streampos fileSize = file.tellg();  // Get file size
    streampos chunkSize = fileSize / numThreads;

    vector<thread> threads;
    vector<List> threadLists(numThreads);

    for (int i = 0; i < numThreads; i++) {
        streampos start = i * chunkSize;
        streampos end = (i == numThreads - 1) ? fileSize : start + chunkSize;

        threads.emplace_back(readChunk, filename, start, end, ref(threadLists[i]));
    }

    for (auto& t : threads) {
        t.join();  // Wait for all threads to finish
    }

    for (List& tList : threadLists) {
        wordList.merge(wordList, tList);  // Assuming List has a merge function
    } 
}