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
    bool call(TreeNode* root, long long lo, long long hi) {
        bool leftOk = (root->left == NULL) || (root->left->val < root->val && root
            ->left->val > lo);
        if(root->left != NULL) leftOk &= call(root->left, lo, root->val);
        
        bool rightOk = (root->right == NULL) || (root->right->val > root->val && root
            ->right->val < hi);
        if(root->right != NULL) rightOk &= call(root->right, root->val, hi);
        
        return leftOk && rightOk;
    }
    bool isValidBST(TreeNode* root) {
        return root == NULL || call(root, -2147483649, 2147483648);
    }
};
