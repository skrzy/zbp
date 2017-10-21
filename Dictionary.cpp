#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "Dictionary.h"

using namespace boost;

Dictionary::Dictionary(vector<string> & words) {
    copy(words.begin(), words.end(), inserter(dictionary, dictionary.begin()));
}

bool Dictionary::contains(string word) {
    return dictionary.count(word)
        || (isupper(word[0]) && dictionary.count(to_lower_copy(word)))
        || (all(word, is_upper()) && dictionary.count(to_first_uppercase(word)));
}

string Dictionary::to_first_uppercase(string word) {
    return word[0] + to_lower_copy(word.substr(1));
}
