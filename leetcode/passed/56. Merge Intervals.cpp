#include <bits/stdc++.h>
using namespace std;

bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first; // 按照 pair 的 first 从小到大排序
}

//区间的左端点用红表示，右端点用蓝表示(红：1，蓝：2)
//①连续的红中，只保留最小的 ②连续的蓝中，只保留最大的 ③若有红 == 蓝 + 1,这两个都划掉
class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        vector<pair<int, int>> cache; //pair.second存放颜色类型 红：1 蓝：2 被划掉的：-1

        for(auto vec: intervals){
            cache.push_back({vec[0], 1});
            cache.push_back({vec[1], 2});
        }
        sort(cache.begin(), cache.end(), comparePairs);

        for(size_t i = 0; i < cache.size(); i++){
            if(i + 1 < cache.size() && cache[i].second == cache[i + 1].second && cache[i].second == 1){
                i++;
                while(cache[i].second == 1) cache[i++].second = -1;
            } 

            while(i + 1 < cache.size() && cache[i].second == cache[i + 1].second && cache[i].second == 2) cache[i++].second = -1;
            while(i + 1 < cache.size() && cache[i].first == cache[i + 1].first - 1 && cache[i].second == 2 && cache[i + 1].second == 1){
                bool left = false;
                while(i >= 0 && cache[i].second !)






                cache[i].second = -1; cache[i + 1].second = -1;
                i++;
            }
            while(i + 1 < cache.size() && cache[i].first == cache[i + 1].first){
                int j = i - 1, k = i;
                bool left = false;
                while(j >= 0){
                    if(cache[j].second == 2) break;
                    if(cache[j].second == 1){
                        left = true;
                        break;
                    }
                }
                if(left){
                    cache[i].second = -1; cache[i + 1].second = -1;
                }
                i++;
            }
        } 

        for(size_t i = 0; i < cache.size(); i++){
            cout << cache[i].first << ' ' << cache[i].second << '\n';
        }

        for(size_t i = 0; i < cache.size(); i++){
            if(cache[i].second == 1){
                ret.push_back({cache[i].first});
                while(cache[i].second != 2) i++;
                ret[ret.size() - 1].push_back(cache[i].first);
            }
        }
        return ret;
    }
};

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());
        for(size_t i = 0; i < intervals.size(); i++){
            vector<int> temp = intervals[i];
            while(i < intervals.size() && intervals[i][0] <= temp[1]){
                temp[1] = max(intervals[i][1], temp[1]);
                temp[0] = min(intervals[i][0], temp[0]);
                i++;
            }
            ret.push_back(temp);
        }
        return ret;
    }
};

