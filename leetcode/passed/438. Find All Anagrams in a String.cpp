#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        unordered_map<char, int> S_map;
        unordered_map<char, int> P_map;
        for(const auto& letter: p) P_map[letter]++;
        for(size_t i {}; i < p.size() - 1; i++) S_map[s[i]]++;

        for(size_t i {}; i + p.size() <= s.size(); i++){
            if(i) S_map[s[i - 1]]--;
            if (S_map.find(s[i - 1]) != S_map.end() && S_map[s[i - 1]] == 0) {
                S_map.erase(s[i - 1]);
            }
            S_map[s[i + p.size() - 1]]++;
            if(S_map == P_map) ret.push_back(i);

            //cout << "\ni =" << i << ":\n";
            //for(auto [letter, count]: S_map) cout << letter << count << ' ';
        }

        return ret;
    }
};
