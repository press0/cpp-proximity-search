#ifndef UNTITLED1_PARAMETERS_H
#define UNTITLED1_PARAMETERS_H

#include <vector>

using namespace std;

//template<typename T> ostream &operator<<(ostream &s, const vector<T> &v);

struct Parameters {
    Parameters() = default;
    Parameters(int argc, char *argv[], bool debug);
    vector<string> argsVector;
    string keyword1;
    string keyword2;
    string filename;
    int range;
    bool debug;
    void print(bool debug);
};


#endif //UNTITLED1_PARAMETERS_H
