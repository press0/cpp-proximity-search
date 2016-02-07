#ifndef UNTITLED1_WORDS_H
#define UNTITLED1_WORDS_H

#include <vector>
#include "Parameters.h"

using namespace std;

template<typename T> ostream &operator<<(ostream &s, const vector<T> &v);

class SearchFileReader {
public:
    SearchFileReader(Parameters &parameters);
    vector<string> get_words();
private:
    vector<string> words;
};


#endif //UNTITLED1_WORDS_H
