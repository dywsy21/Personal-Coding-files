bool recur(struct TreeNode* left, struct TreeNode* right){ //镜像的左右节点
    if(!left && !right) return true;
    if((!left && right) || (left && !right)) return false;
    if(left->val != right->val) return false;
    
    //if((left->left && right->right && left->left->val != right->right->val) || (left->right && right->left && left->right->val != right->left->val)) return false;
    
    return recur(left->left, right->right) && recur(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    return recur(root->left, root->right);
}