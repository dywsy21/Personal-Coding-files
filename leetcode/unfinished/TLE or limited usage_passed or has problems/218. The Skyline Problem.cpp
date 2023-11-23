#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Define the vector of priority queues to store heights at each x-coordinate
        vector<priority_queue<int>> pqs;
        priority_queue<int> maxXcoord; // A max heap to keep track of the rightmost x-coordinate
        vector<vector<int>> ret;

        // Determine the maximum x-coordinate by iterating through the buildings
        for (auto building : buildings) {
            maxXcoord.push(building[1]);
        }

        // Resize the pqs vector based on the maximum x-coordinate
        int max_x = maxXcoord.top();
        if(max_x == INT_MAX) pqs.resize(INT_MAX);
        else pqs.resize(max_x + 2);

        // Fill the priority queues with heights for each building
        for (auto building : buildings) {
            for (int xcoord = building[0]; xcoord <= building[1]; xcoord++) {
                pqs[xcoord].push(building[2]);
            }
        }

        int prevHeight = 0;

        for (int xcoord = 0; xcoord <= max_x; xcoord++) {
            if(xcoord>0 && pqs[xcoord-1].empty()) prevHeight = 0;

            if (!pqs[xcoord].empty()) {
                int currMaxHeight = pqs[xcoord].top();
                if (currMaxHeight > prevHeight) {
                    ret.push_back({xcoord,currMaxHeight});
                    prevHeight = currMaxHeight;                    
                }
                if (currMaxHeight < prevHeight) {
                    ret.push_back({xcoord - 1,currMaxHeight});
                    prevHeight = currMaxHeight;                 
                }
                if(pqs[xcoord + 1].empty()) ret.push_back({xcoord,0});
            }
        }
        return ret;
    }
};
