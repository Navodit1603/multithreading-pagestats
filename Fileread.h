#ifndef FILE_READER_H
#define FILE_READER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>  // For ispunct and isspace
#include "Linklist.h"

// Removes punctuation from a given word.
std::string cleanWord(const std::string& word);

// Reads sentences from a file and inserts cleaned words into the linked list.
void readFileToList(const std::string& filename, List& wordList);

#endif // FILE_READER_H