#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        ll ret {};
        vector<vector<int>> store(roads.size() + 1);
        for(auto road: roads){
            store[road[0]].push_back(road[1]);
            store[road[1]].push_back(road[0]);
        }

        function<int(int, int)> dfs = [&](int cur, int father){
            int size = 1;
            for(auto dest: store[cur]){
                if(dest != father) size += dfs(dest, cur);
            }
            if(cur) ret += (size - 1) / seats + 1;
            return size;
        };

        dfs(0, -1);
        return ret;
    }
};