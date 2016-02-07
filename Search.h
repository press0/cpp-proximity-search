#ifndef UNTITLED1_SEARCH_H
#define UNTITLED1_SEARCH_H

#include "Parameters.h"
#include "SearchFileReader.h"
#include "ForwardSearchFifoQueue.h"

using namespace std;

class Search {
public:
    Search() = default;
    Search(int argc, char *argv[], bool debug);
    void run();
private:
    void print1(bool debug, int i, vector<pair<string, string>> results);
    void print2(bool debug, vector<string> words, vector<pair<string, string>> results);
    vector<pair<string, string>> searchResults;
    vector<pair<string, string>> tmp;
    Parameters *parameters;
    SearchFileReader *fileReader;
    ForwardSearchFifoQueue *queue;
};


#endif //UNTITLED1_SEARCH_H
