#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<string, vector<string>> mymap;

        for(auto& str: strs){
            string count(26, '0');
            for(auto& letter: str) count[letter - 'a']++;
            mymap[count].emplace_back(str);
        }
        for(auto& [str, vec]: mymap) ret.emplace_back(vec);
        return ret;
    }
};