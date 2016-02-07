#include <iostream>
#include "Search.h"

Search::Search(int argc, char **argv, bool debug) {
    parameters = new Parameters(argc, argv, debug);
    fileReader = new SearchFileReader(*parameters);
    queue = new ForwardSearchFifoQueue(*parameters);
}

void Search::run() {
    for (int i=0; i < fileReader->get_words().size(); i++) {
        tmp = queue->push(fileReader->get_words()[i]);
        searchResults.reserve(searchResults.size() + tmp.size());
        searchResults.insert(searchResults.end(),
                             std::make_move_iterator(tmp.begin()),
                             std::make_move_iterator(tmp.end()));
        print1(parameters->debug, i, tmp);
    }
    print2(parameters->debug, fileReader->get_words(), searchResults);
    cout << searchResults.size() << endl;
}

void Search::print1(bool debug, int i, vector<pair<string, string>> results) {
    if (debug && results.size() > 0) {
        cout << "results i=: " << i << endl;
        for (int j = 0; j < results.size(); j++) {
            cout << results[j].first << ", " << results[j].second << endl;
        }
    }
}

void Search::print2(bool debug, vector<string> words, vector<pair<string, string>> results) {
    if (debug) {
        //big cout << "searching: " << words << endl;
        cout << "searchResults: " << endl;
        for (int i = 0; i < results.size(); i++) {
            cout << results[i].first << ", " << results[i].second << endl;
        }
    }
}

