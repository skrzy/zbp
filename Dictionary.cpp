#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "Dictionary.h"

Dictionary::Dictionary(vector<string> words) {
    copy(words.begin(), words.end(), inserter(dictionary, dictionary.begin()));
}

bool Dictionary::contains(string word) {

    if (dictionary.count(word)) {
        return true;
    }

    if (isupper(word[0])
        && dictionary.count(boost::to_lower_copy(word))) {
        return true;
    }
    if (boost::all(word, boost::is_upper())) {
        string first_uppercase = word[0] + boost::to_lower_copy(word.substr(1));
        if (dictionary.count(first_uppercase)) {
            return true;
        }
    }
    return false;
}
