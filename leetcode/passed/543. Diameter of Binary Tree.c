struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int result = 0;

int max(int a, int b){
    return a > b ? a : b;
}
int maxDepth(struct TreeNode* root) {
    if(!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int root_path_max_len(struct TreeNode* root){ //returns the maximum path_length where the path contains root
    if(!root) return 0;
    return maxDepth(root->left) + maxDepth(root->right);
}

void find_result(struct TreeNode* root){
    if(!root) return;
    result = max(result, root_path_max_len(root));
    find_result(root->left); find_result(root->right);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    result = 0;
    find_result(root);
    return result;
}