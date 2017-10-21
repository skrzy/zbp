#include <algorithm>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/trim_all.hpp>
#include "Z2.h"
#include "Dictionary.h"

using namespace boost;

void Z2::run(vector<string> & words, const string & file_name) {

    random_shuffle(words.begin(), words.end());

    Dictionary dictionary(words);

    ifstream file_stream(file_name);

    if (file_stream.is_open()) {
        string line;
        while (getline(file_stream, line)) {
            vector<string> words_in_line;
            string trimmed_line = trim_all_copy_if(line, is_any_of(" .,:"));
            split(words_in_line, trimmed_line, is_any_of(" .,:"));
            for (auto word : words_in_line) {
                if (!dictionary.contains(word)) {
                    cout << "Incorrect word: " << word << " -> Line: " << line << endl;
                }
            }
        }
    }
}
