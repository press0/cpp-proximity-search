#include <iostream>
#include "ForwardSearchFifoQueue.h"

ForwardSearchFifoQueue::ForwardSearchFifoQueue(Parameters &parameters) {
    this->parameters = parameters;
    for(int i=0; i<parameters.range; i++) {
        queue1.push_front("");
    }
    if (parameters.debug) {
        std::cout << "queue1 size:" << queue1.size() << endl;
    }
}

vector<pair<string, string>> ForwardSearchFifoQueue::push(string topItem) {
    vector<pair<string, string>> searchResults;
    queue1.pop_back();
    queue1.push_front(topItem);
    //if right item is a keyword
    if (keyword(topItem)) {
        for(int i=0; i< queue1.size(); i++) {
            //if left item is the other keyword
            if (otherKeyWord(queue1[i], topItem)) {
                searchResults.push_back((make_pair(queue1[i],topItem)));
            }
        }
    }
    return searchResults;
}

bool ForwardSearchFifoQueue::otherKeyWord(string item, string topItem) {
    int i1 = item.compare(parameters.keyword1);
    int i2 = item.compare(parameters.keyword2);
    int i3 = item.compare(topItem);
    return ((i1==0 || i2==0) && i3!=0);
}

bool ForwardSearchFifoQueue::keyword(string item) {
    int i1 = item.compare(parameters.keyword1);
    int i2 = item.compare(parameters.keyword2);
    return (i1==0 || i2==0);
}
