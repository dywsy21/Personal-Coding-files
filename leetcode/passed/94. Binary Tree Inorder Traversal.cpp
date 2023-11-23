#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> ret;
        vector<int> left = inorderTraversal(root->left);
        ret.insert(ret.end(), left.begin(), left.end());
        ret.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }
};
