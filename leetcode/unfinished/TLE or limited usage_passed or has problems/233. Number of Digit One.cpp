#include<bits/stdc++.h>
using namespace std;


//递归过多次会导致栈溢出
/*
class Solution {
public:
    int countDigitOne(int n) {
        if(!n) return 0;
        int ret = 0;
        string num = to_string(n);
        for(auto i: num) if(i == '1') ret++;
        ret += countDigitOne(n - 1);
        return ret;
    }
};
*/

class Solution {
public:
    int countDigitOne(int n) {
        if(!n) return 0;
        int ret = 0;
        for(int i=1; i<=n; i++){
            string num = to_string(i);
            for(auto j : num) if(j == '1') ret++;
        }
        return ret;
    }
};