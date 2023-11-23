#include <bits/stdc++.h>
using namespace std;



#define max(a,b) ((a)>=(b)?(a):(b))

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashtable;
        int ret=0, j=0;
        for(int i=0; i<s.length(); i++){
            if(i>0) hashtable.erase(s[i-1]);
            while(hashtable.find(s[j]) == hashtable.end() && j<s.length()){
                hashtable.insert(s[j]);                    //j<s.length()很关键！！address sanitizer不会报这个错
cout << s[j] << " " << j << " ";
                j++;
                ret = max(ret, hashtable.size());
cout << hashtable.size() << "\n";
            }
        }
        return ret;
    }
};