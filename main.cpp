#include <iostream>
#include "Search.h"

using namespace std;

int main(int argc, char *argv[]) {
    Search *search = new Search(argc, argv, false);
    search->run();
}

