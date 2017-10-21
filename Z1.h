#ifndef ZBP1_Z1_H
#define ZBP1_Z1_H

#include <vector>
#include <string>
#include <functional>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Z1 {

public:
    void run(vector<string> & dictionary);

private:
    duration<double> measure(function<void ()> &foo);

};


#endif //ZBP1_Z1_H
