#include <iostream>
#include <vector>
#include "Parameters.h"

template<typename T> ostream &operator<<(ostream &s, const vector<T> &v) {
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto &e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}

Parameters::Parameters(int argc, char *argv[], bool debug1) {
    for (int i = 0; i < argc; ++i) {
        argsVector.push_back(argv[i]);
    }
    argsVector.erase(argsVector.begin());
    keyword1 = argsVector[0];
    keyword2 = argsVector[1];
    range = std::stoi(argsVector[2]);
    filename = argsVector[3];
    debug = debug1;
    print(debug);
}

void Parameters::print(bool debug) {
        if (debug) {
            cout << "command line parameters: " << argsVector << endl;
            cout << "Parameters: "
            << "[keyword1: " << keyword1
            << ", keyword2: " << keyword2
            << ", range: " << range
            << ", filename: " << filename
            << ", debug: " << debug
            << "]"
            << endl;
        }
}

