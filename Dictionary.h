#ifndef ZBP_DICTIONARY_H
#define ZBP_DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Dictionary {
private:
    unordered_set<string> dictionary;
public:
    Dictionary(vector<string> words);
    bool contains(string word);
private:
    string to_first_uppercase(string word);
};


#endif //ZBP_DICTIONARY_H
