#include <algorithm>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "Z2.h"
#include "Dictionary.h"

void Z2::run(vector<string> words, const string &file_name) {

    random_shuffle(words.begin(), words.end());

    Dictionary dictionary(words);

    ifstream file_stream(file_name);

    if (file_stream.is_open()) {
        string line;
        while (getline(file_stream, line)) {
            vector<string> words_in_line;
            boost::split(words_in_line, line, boost::is_any_of(" .,"));
            for (auto word : words_in_line) {
                if (dictionary.contains(word)) {
                    cout << word << endl;
                }
            }
        }
    }
}
