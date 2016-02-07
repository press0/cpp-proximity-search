#ifndef UNTITLED1_PROXIMITYFIFOQUEUE_H
#define UNTITLED1_PROXIMITYFIFOQUEUE_H

#include <deque>
#include <vector>
#include <string>
#include <utility>
#include "Parameters.h"

using namespace std;

class ForwardSearchFifoQueue {

public:
    ForwardSearchFifoQueue(Parameters &parameters);
    vector<pair<string, string>> push(string itemTop);

private:
    deque<string> queue1;
    Parameters parameters;
    bool keyword(string item);
    bool otherKeyWord(string item, string topItem);
};


#endif //UNTITLED1_PROXIMITYFIFOQUEUE_H
