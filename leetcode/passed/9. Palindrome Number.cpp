#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str1 = to_string(x);
        auto str2 = str1;
        reverse(str1.begin(), str1.end());
        return str1 == str2;
    }
};