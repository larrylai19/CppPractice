class Solution {
public:
    
    int maxDepth(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        // 終止條件
        if(!root) 
            return 0;
        // 包含 root 的最長路徑
        int middle = maxDepth(root->left) + maxDepth(root->right);
        // 只有右邊的最長路徑
        int right = diameterOfBinaryTree(root->right);
        // 只有左邊的最長路徑
        int left = diameterOfBinaryTree(root->left);
        
        return max(middle, max(right, left));
    }
};