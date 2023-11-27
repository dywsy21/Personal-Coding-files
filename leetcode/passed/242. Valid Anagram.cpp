#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> S_count;
        unordered_map<char, int> T_count;

        for(const auto& character: s) S_count[character]++;
        for(const auto& character: t) T_count[character]++;

        return S_count == T_count;

    }
};