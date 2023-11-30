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

//prefix traversal: root, left, right
void preorder(TreeNode* root){
    if(root == nullptr) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

//infix traversal: left, root, right
void inorder(TreeNode* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

//postfix traversal: left, right, root
void postorder(TreeNode* root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}