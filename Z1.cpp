#include <algorithm>
#include <set>
#include <iostream>
#include <unordered_set>
#include "Z1.h"

void Z1::run(vector<string> dictionary) {

    random_shuffle(dictionary.begin(), dictionary.end());


    set<string> ordered_set;
    function<void ()> fill_ordered_set = [&dictionary, &ordered_set]{
        copy(dictionary.begin(), dictionary.end(), inserter(ordered_set, ordered_set.begin()));
    };
    cout << "ordered ordered_set insert: " << measure(fill_ordered_set).count() << " sec." << endl;


    unordered_set<string> unordered_set;
    function<void ()> fill_unordered_set = [&dictionary, &unordered_set]{
        copy(dictionary.begin(), dictionary.end(), inserter(unordered_set, unordered_set.begin()));
    };
    cout << "unordered ordered_set insert: " << measure(fill_unordered_set).count() << " sec." << endl;


    random_shuffle(dictionary.begin(), dictionary.end());

    // TODO find zamiast count?
    function<void ()> ordered_set_search = [&dictionary, &ordered_set]{
        for (auto entry: dictionary) {
            ordered_set.find(entry);
        }
    };
    cout << "ordered set find: " << measure(ordered_set_search).count() << " sec." << endl;

    function<void ()> unordered_set_search = [&dictionary, &unordered_set]{
        for (auto entry: dictionary) {
            unordered_set.find(entry);
        }
    };
    cout << "unordered ordered_set: " << measure(unordered_set_search).count() << " sec." << endl;

}

duration<double> Z1::measure(function<void()> &foo) {
    high_resolution_clock::time_point clk1 = high_resolution_clock::now();
    foo();
    high_resolution_clock::time_point clk2 = high_resolution_clock::now();
    return duration_cast<duration<double>>(clk2 - clk1);
}
