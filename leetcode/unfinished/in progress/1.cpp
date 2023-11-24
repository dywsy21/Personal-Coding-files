#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> generate_info(int n, vector<vector<int>> edges){
//info[i] = {{destination, distance},......}
    vector<vector<vector<int>>> info(n);
    for(int i = 0; i < edges.size(); i++){
        info[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        info[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    return info;
}

unordered_set<int> findpath(int initial, int cur, int distanceThreshold, int banned_destination, vector<vector<vector<int>>> info){
    if(distanceThreshold < 0){
        return {};
    }
    unordered_set<int> cities;
    int citynum = info[cur].size();
    if(initial != cur) cities.insert(cur);
    for(int i = 0; i < citynum; i++){
        if(info[cur][i][0] == banned_destination || info[cur][i][0] == initial){
            continue;
        }
        if(info[cur][i][1] <= distanceThreshold){
            auto reachable_cities = findpath(initial, info[cur][i][0], distanceThreshold - info[cur][i][1], i, info);
            cities.insert(reachable_cities.begin(), reachable_cities.end());
        }
    }
    return cities;
}

class Solution {
public:
    int findTheCity(int n, vector<vector<int>> edges, int distanceThreshold) {
        auto info = generate_info(n, edges);
        vector<int> count(n, 0);
        int minnum = INT_MAX;
        int maxindex = -1;

        for(int i = 0; i < n; i++){
            count[i] = findpath(i, i, distanceThreshold, -1, info).size();
            cout << "count[" << i << "]" << " finished." << endl;
            if(count[i] <= minnum){
                minnum = count[i];
                maxindex = i;
            }
        }
        for(int i = 0; i < n; i++){
            cout << count[i] << " ";
        }
        cout << endl; //print a newline

        return maxindex;
    }
};  
