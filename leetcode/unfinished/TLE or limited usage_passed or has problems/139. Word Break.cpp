#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool my_word_break(string s, unordered_set<int> sizes, unordered_set<string> words, size_t i){
        if(i >= s.size()) return true;
        bool found = false;
        for(auto& size: sizes){
            if(words.find(s.substr(i, size)) != words.end() && my_word_break(s, sizes, words, i + size)){
                found = true;
                break;
            }
        }
        return found;
    }
        

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<int> sizes;
        unordered_set<string> words;
        for(auto& word: wordDict){
            sizes.insert(word.size());
            words.insert(word);
        }
        return my_word_break(s, sizes, words, 0);
    }
};