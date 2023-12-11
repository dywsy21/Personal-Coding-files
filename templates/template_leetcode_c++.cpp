#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 并查集模板
class UnionFind {        //该并查集模板的元素全为自然数(0 ~ n - 1)，相当于把原来的图中的节点编个号得到的抽象后的版本
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

    void reset(int _n){
        n = _n;
        setCount = _n;
        root.resize(_n);
        setSize.resize(_n, 1);
        for(int i = 0; i < _n; i++) root[i] = i;
    }

    void reset(){
        setCount = n;
        for(int i = 0; i < n; i++) root[i] = i;
        for(int i = 0; i < n; i++) setSize[i] = 1;
    }
};
