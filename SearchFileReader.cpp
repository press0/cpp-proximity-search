#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include "SearchFileReader.h"

const vector<string> parse(const string &s, const char &c) {
    string buff{""};
    vector<string> v;

    for(auto n:s)
    {
        if(n != c) buff+=n; else
        if(n == c && buff != "") { v.push_back(buff); buff = ""; }
    }
    if(buff != "") v.push_back(buff);

    return v;
}

template<typename T> ostream &operator<<(ostream &s, const vector<T> &v) {
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto &e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}

SearchFileReader::SearchFileReader(Parameters &parameters) {

    const string PATH; //IDE home directory;

    string line;
    string filePath = PATH + parameters.filename;
    ifstream myfile (filePath);
    vector<string> lineWords;

    if (myfile.is_open()) {
        while ( getline (myfile,line) )
        {
            lineWords = parse(line, ' ');
            words.insert(end(words), begin(lineWords), end(lineWords));
        }
        myfile.close();
    } else {
        cerr << "Unable to open file";
    }

    if (parameters.debug) {
        cout << "word count:" << words.size() << endl;
        //too big cout << "words: " << words << endl;
    }

}

vector<string> SearchFileReader::get_words() {
    return words;
}

