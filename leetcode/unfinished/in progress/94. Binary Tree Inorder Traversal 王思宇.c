int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if(!root){
        *returnSize = 0;
        return NULL;
    }
    int left_size = 0, right_size = 0;
    int *left = inorderTraversal(root->left, &left_size);
    int *right = inorderTraversal(root->right, &right_size);
    int *res = (int*)malloc(sizeof(int)*(left_size + right_size + 1));

    for(int i = 0; i < left_size; i++){
        res[i] = left[i];
    }

    res[left_size] = root->val;

    for(int i = 0; i < right_size; i++){
        res[left_size + 1 + i] = right[i];
    }

    *returnSize = left_size + right_size + 1;
    return res;
}