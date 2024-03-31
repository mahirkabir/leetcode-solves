/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans;
    int k;
    int rank;
    void call(TreeNode* root) {
        if(root->left != NULL)
            call(root->left);
        
        ++rank;
        if(rank == k)
            ans = root->val;
        
        if(root->right != NULL)
            call(root->right);
    }
    
    int kthSmallest(TreeNode* root, int _k) {
        k = _k;
        rank = 0;
        
        if(root != NULL)
            call(root);
        
        return ans;
    }
};
