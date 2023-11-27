#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse_single_words(string& s){
        size_t i{};
        while(i < s.size()){
            auto temp = i;
            while(i < s.size() && s[i] != ' ') i++;
            reverse(s.begin() + temp, s.begin() + i);

            if(i) i++;
            while(i < s.size() && s[i] == ' '){
                s.erase(i, 1);
                i++;
            }
        }
    }

    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        reverse_single_words(s);
        return s;
    }
};