#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string my_countAndSay(string s){
        string ret;
        for(int i = 0; i < s.size(); i++){
            int count = 1;
            while(i + 1 < s.size() && s[i+1] == s[i]){
                count++;
                i++;
            }
            ret += to_string(count);
            ret += s[i];
        }
        return ret;
    }

    string countAndSay(int n) {
        int i {2};
        string s {"1"};
        while(i++ <= n) s = my_countAndSay(s);
        return s;
    }
};