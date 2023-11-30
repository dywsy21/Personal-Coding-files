#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_set<char> alp1, alp2;
        unordered_map<char, int> raw1, raw2; 
        unordered_map<int, int> map1, map2; //<字母出现次数,该出现次数的出现次数>
        for(auto letter: word1) {raw1[letter]++; alp1.insert(letter);}
        for(auto letter: word2) {raw2[letter]++; alp2.insert(letter);}
        if(alp1 != alp2) return false;
        for(auto [_, count]: raw1) map1[count]++;
        for(auto [_, count]: raw2) map2[count]++;
        return map1 == map2;
    }
};