#include <bits/stdc++.h>
using namespace std;


vector<vector<pair<int, int>>> generate_info(int n, vector<vector<int>>& edges){
    //info[i] = {{destination, distance},......}
    vector<vector<pair<int, int>>> info(n);
    for(int i = 0; i < edges.size(); i++){
        info[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        info[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    return info;
}


//TODO: debug this function
//return the cities that can be reached from city cur
unordered_set<int> findpath(int initial, int cur, int travelled_distance, int distanceThreshold, vector<vector<pair<int, int>>> info, unordered_map<int, int>& visited){
    if(travelled_distance >= distanceThreshold){
        return unordered_set<int>();
    }
    visited[cur] = min(travelled_distance, visited[cur]);

    unordered_set<int> ret{cur};

    for(auto [next, distance] : info[cur]){
        if(visited.find(next) != visited.end() && visited[next] <= travelled_distance + distance){
            continue;
        }
        ret.merge(findpath(initial, next, travelled_distance + distance, distanceThreshold, info, visited));
    }
    cout << initial << " -> " << cur << " : " << travelled_distance << " " << ret.size() << endl;
    return ret;
}

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        auto info = generate_info(n, edges);
        vector<int> count(n, 0); //initialize the count vector with the correct size
        int minnum = INT_MAX;
        int maxindex = -1;
        for(int i = 0; i < n; i++){
            unordered_map<int, int> visited;
            count[i] = findpath(i, i, 0, distanceThreshold, info, visited).size() - 1;
            cout << "count[" << i << "] = " << " finished." << endl;
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
