#include <bits/stdc++.h>
using namespace std;

int generate(vector<int> expo){
    return (int)pow(2, expo[0]) * (int)pow(3, expo[1]) * (int)pow(5, expo[2]);
}



class Solution {
public:
    int nthUglyNumber(int n) {
        int ptr_1 = 0, ptr_2 = 0, ptr_3 = 0, count = 0;
        vector<vector<int>> last_expos {{1,0,0},{0,1,0},{0,0,1}}; // last_expos[0]:-1 [1]:-2 [2]:-3 这个顺序是为了用pop_back
        while(count <= n){
            







        }
    }
};