#include <iostream>
#include <fstream>
#include <string>
#include "Linklist.h"
#include "Fileread.h"

int regular(string filename){
    List wordList;
    readFileToList(filename, wordList);
    wordList.printList();

    return 0;
}


int main(int argc, char* argv[]) {
    string filename = argv[1];
    regular(filename);
    return 0;
}