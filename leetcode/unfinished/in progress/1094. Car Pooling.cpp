#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //<from, num> <to, num>
        unordered_map<int, int> diff_num;
        unordered_set<int> raw_stops;
        vector<int> stops;
        for(auto trip: trips){
            diff_num[trip[1]] += trip[0];
            diff_num[trip[2]] -= trip[0];
            raw_stops.insert(trip[1]); raw_stops.insert(trip[2]);
        }
        for(auto stop: raw_stops) stops.push_back(stop);
        sort(stops.begin(), stops.end());

        int cur{};
        for(auto stop: stops){
            cur += diff_num[stop];
            if(cur > capacity) return false;
        }
        return true;
    }
};