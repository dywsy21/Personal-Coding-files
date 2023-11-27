#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int neg = -1;
        if(x > 0) neg = 1;
        string str = to_string(x);
        reverse(str.begin(), str.end());
        long long ans;
        istringstream(str) >> ans;
        ans *= neg;
        if(ans > INT_MAX || ans < INT_MIN) return 0;
        else return ans;
    }
};