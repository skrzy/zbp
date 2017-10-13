#include <algorithm>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "Z2.h"

void Z2::run(vector<string> dictionary, const string &file_name) {

    random_shuffle(dictionary.begin(), dictionary.end());

    unordered_set<string> dictionary_set;
    copy(dictionary.begin(), dictionary.end(), inserter(dictionary_set, dictionary_set.begin()));


    ifstream file_stream(file_name);

    if (file_stream.is_open()) {
        string line;
        while (getline(file_stream, line)) {
            dictionary.push_back(line);
            vector<string> str;
            boost::split(str, line, boost::is_any_of(" "));
            for (auto s : str) {
                cout << s << endl;
            }
        }
    }
}
