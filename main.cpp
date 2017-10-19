#include <iostream>
#include <fstream>
#include <vector>
#include "Z1.h"
#include "Z2.h"

using namespace std;

int main(int argc, char * argv[]) {

    if (argc < 3) {
        cout << "Invalid arguments" << endl;
        return -1;
    }

    string file_name = argv[2];
    ifstream dictionary_fs(file_name);
    vector<string> dictionary;

    if (dictionary_fs.is_open()) {
        string line;
        while (getline(dictionary_fs, line)) {
            dictionary.push_back(line);
        }
        cout << dictionary.size() << " lines" << endl;
    }


    string mode = argv[1];
    if (mode == "-m") {
        Z1 z1;
        z1.run(dictionary);
    } else if (mode == "-s") {
        string text_file = argv[3];
        Z2 z2;
        z2.run(dictionary, text_file);
    } else {
        cout << "Invalid arguments" << endl;
        return -1;
    }

    return 0;
}
