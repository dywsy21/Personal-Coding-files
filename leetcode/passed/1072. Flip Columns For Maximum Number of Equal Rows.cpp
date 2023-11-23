#include <bits/stdc++.h>
using namespace std;

//GPT生成的struct VectorHash，不是最优解但能用
/*
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<vector<int>, int, VectorHash> hashmap;

        for(int i = 0; i < matrix.size(); i++) {
            vector<int> vec0, vec1;
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) vec0.push_back(j);
                if(matrix[i][j] == 1) vec1.push_back(j);
            }
            hashmap[vec0]++;
            hashmap[vec1]++;
        }
        int ret = 0;
        for(const auto& pair : hashmap) ret = max(ret, pair.second);
        return ret;
    }
};
*/


//可以用<string, int>的键值对，以避免C++库里没有对vector写hash的尴尬情况
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> hashmap;

        for(int i = 0; i < matrix.size(); i++) {
            string str0, str1;
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) str0.push_back(j);
                if(matrix[i][j] == 1) str1.push_back(j);
            }
            hashmap[str0]++;
            hashmap[str1]++;
        }
        int ret = 0;
        for(const auto& pair : hashmap) ret = max(ret, pair.second);
        return ret;
    }
};