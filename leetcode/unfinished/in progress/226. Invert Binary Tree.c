struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void recur(struct TreeNode* root){
    if(!root) return;
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    recur(root->left);
    recur(root->right);
}


struct TreeNode* invertTree(struct TreeNode* root) {
    recur(root);
    return root;
}