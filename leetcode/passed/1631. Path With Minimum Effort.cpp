#include<bits/stdc++.h>
using namespace std;

/* 
!abandoned
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> r(m, vector<int>(n, -1));
        vector<vector<int>> used(m, vector<int>(n, 0));

        function<int(int, int, vector<vector<int>>)> recur = [&](int i, int j, vector<vector<int>> used){
            //0 for not used, 1 for used
            if(i == 0 && j == 0){
                r[0][0] = 0;
                return 0;
            }
            if(r[i][j] >= 0) return r[i][j];

            //1, 2, 3, 4  -> left, up, down, right
            if(j >= 1 && !used[i][j - 1])    {used[i][j - 1] = 1; int left  = r[i][j - 1] >= 0 ? max(r[i][j - 1], abs(heights[i][j] - heights[i][j - 1])) : max(recur(i, j - 1, used), abs(heights[i][j] - heights[i][j - 1])); r[i][j] = min(r[i][j], left);}
            if(i >= 1 && !used[i - 1][j])    {used[i - 1][j] = 1; int up    = r[i - 1][j] >= 0 ? max(r[i - 1][j], abs(heights[i][j] - heights[i - 1][j])) : max(recur(i - 1, j, used), abs(heights[i][j] - heights[i - 1][j])); r[i][j] = min(r[i][j], up);}
            if(i < m - 1 && !used[i + 1][j]) {used[i + 1][j] = 1; int down  = r[i + 1][j] >= 0 ? max(r[i + 1][j], abs(heights[i][j] - heights[i + 1][j])) : max(recur(i + 1, j, used), abs(heights[i][j] - heights[i + 1][j])); r[i][j] = min(r[i][j], down);}
            if(j < n - 1 && !used[i][j + 1]) {used[i][j + 1] = 1; int right = r[i][j + 1] >= 0 ? max(r[i][j + 1], abs(heights[i][j] - heights[i][j + 1])) : max(recur(i, j + 1, used), abs(heights[i][j] - heights[i][j + 1])); r[i][j] = min(r[i][j], right);}

            return r[i][j];
        };

        recur(m - 1, n - 1, used);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) cout << r[i][j] << " ";
            cout << endl;
        }
        return r[m - 1][n - 1];
    }
};
*/

// 并查集模板
class UnionFind {        //该并查集模板仅适用于元素全为自然数(0 ~ n - 1)的情况
    vector<int> root;    // root[i] = j 表示i的根节点是j
    vector<int> setSize; // size[i] = j 表示i所在的连通分量大小为j (连通分量：互相连通的节点集合)
    int n;               // 总元素数目
    int setCount;        // 当前连通分量数目(连通分量数目会随着合并而减少) 
                         // 连通分量数目也即不同的互相不连通的集合数目
public:
    UnionFind(int _n): n(_n), setCount(_n), root(_n), setSize(_n, 1) {
        for(int i = 0; i < _n; i++) root[i] = i;  // 初始化，每个元素的根节点都是自己
    }
    
    int findRoot(int x) {
        if(x == root[x]) return x;                // x的父节点是自己，说明x是根节点，直接返回x
        else{
            root[x] = findRoot(root[x]);          // x的父节点不是自己，说明x不是根节点，递归寻找x的父节点的父节点
            return root[x];                       // 递归寻找到x的根节点后，将root[x]更新为根节点，然后返回根节点
        }
        //return root[x] == x ? x : root[x] = findRoot(root[x]); 简单写法
    }

    bool isConnected(int x, int y) {
        return findRoot(x) == findRoot(y);
    }

    bool unite(int x, int y) {                      //将小的连通分量的根节点连到大的连通分量的根节点上
        int x_root = findRoot(x);                   // x的根节点
        int y_root = findRoot(y);                   // y的根节点
        if(x_root == y_root) return false;          // x和y已经连通，不需要再合并

        if (setSize[x_root] < setSize[y_root]) swap(x_root, y_root);   // 保证x的连通分量大小大于y的连通分量大小

        root[y_root] = x_root;                      // 将y的根节点连到x的根节点上
        setSize[x_root] += setSize[y_root];         // 更新x的连通分量大小
        setCount--;
        return true;
    }
};


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        UnionFind uf(m * n);
        vector<vector<int>> edges; // edges[i] = {权重, 顶点1, 顶点2}
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int id = i * n + j;
                if(i > 0) edges.push_back({abs(heights[i][j] - heights[i - 1][j]), id, id - n});
                if(j > 0) edges.push_back({abs(heights[i][j] - heights[i][j - 1]), id, id - 1});
            }
        }
        sort(edges.begin(), edges.end()); // 按权重从小到大排序

        for(auto edge: edges){
            int len = edge[0], id1 = edge[1], id2 = edge[2];
            uf.unite(id1, id2);
            if(uf.isConnected(0, m * n - 1)) return len;
        }
        return 0;  //这里return 0很有讲究，如果矩阵是1*1的，那么前面的edges为空，会到这里才return，所以必须return 0
    }
};


int main() {
    Solution s;
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    int result = s.minimumEffortPath(heights);
    cout << "Minimum effort path: " << result << endl;
    getchar();
    return 0;
}
