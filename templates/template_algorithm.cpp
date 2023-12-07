#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

//any_of, none_of, all_of
    vector<int> v = {1, 2, 3, 4, 5};
    if (any_of(v.begin(), v.end(), [](int i) { return i < 0; })) {
        cout << "There are negative elements in the range." << endl;
    } else {
        cout << "There are no negative elements in the range." << endl;
    }
//for_each
    for_each(v.begin(), v.end(), [](int i) { cout << i << " "; });
    cout << endl;

//find, find_if, find_if_not
//returns the iterator of the found element, or the end iterator if not found
    auto it = find(v.begin(), v.end(), 3);
    if (it != v.end()) {
        cout << "Found " << *it << endl;
    } else {
        cout << "Not found" << endl;
    }

//find_first_of, find_end_of (note: O(n^2))
//find_first_of: returns the iterator of the first element of the found subsequence, or the end iterator if not found
//find_end_of: returns the iterator of the first element of the last found subsequence, or the end iterator if not found
    vector<int> v2 = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    auto it2 = find_first_of(v2.begin(), v2.end(), v.begin(), v.end());
    if (it2 != v2.end()) {
        cout << "Found " << *it2 << endl;
    } else {
        cout << "Not found" << endl;
    }

//adjacent_find
//returns the iterator of the first element of the found adjacent pair, or the end iterator if not found
    auto it3 = adjacent_find(v2.begin(), v2.end());
    if (it3 != v2.end()) {
        cout << "Found " << *it3 << endl;
    } else {
        cout << "Not found" << endl;
    }

//count, count_if (returns int)
    cout << count(v.begin(), v.end(), 3) << endl;
    cout << count_if(v.begin(), v.end(), [](int i) { return i % 2 == 0; }) << endl;

//mismatch
//returns a pair of iterators, the first iterator points to the first element of the first mismatched pair, the second iterator points to the first element of the second mismatched pair
    vector<int> v3 = {1, 2, 3, 4, 5};
    vector<int> v4 = {1, 2, 3, 4, 6};
    auto it4 = mismatch(v3.begin(), v3.end(), v4.begin());
    if (it4.first != v3.end()) {
        cout << "Found " << *it4.first << " and " << *it4.second << endl;
    } else {
        cout << "Not found" << endl;
    }

//is_permutation
//returns true if the second range is a permutation of the first range
    vector<int> v5 = {1, 2, 3, 4, 5};
    vector<int> v6 = {2, 4, 3, 5, 1};
    if (is_permutation(v5.begin(), v5.end(), v6.begin())) {
        cout << "Is permutation" << endl;
    } else {
        cout << "Is not permutation" << endl;
    }

//search
//returns the iterator of the first element of the found subsequence, or the end iterator if not found
    vector<int> v7 = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    vector<int> v8 = {1, 2, 3};
    auto it5 = search(v7.begin(), v7.end(), v8.begin(), v8.end());
    if (it5 != v7.end()) {
        cout << "Found " << *it5 << endl;
    } else {
        cout << "Not found" << endl;
    }

//search_n
//returns the iterator of the first element of the found subsequence, or the end iterator if not found
    vector<string> v9 = {"wow", "wow", "wow", "hi", "wow"};
    auto it6 = search_n(v9.begin(), v9.end(), 4, "wow");
    if (it6 != v9.end()) {
        cout << "Found " << *it6 << endl;
    } else {
        cout << "Not found" << endl;
    }

    auto it7 = search_n(v9.begin(), v9.end(), 3, "wow");
    if (it7 != v9.end()) {
        cout << "Found " << *it7 << endl;
    } else {
        cout << "Not found" << endl;
    }


    
    getchar();
    return 0;
}