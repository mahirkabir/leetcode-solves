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
    int call(TreeNode* pos, int isleft) {
        if(pos == NULL) return 0;
        if(pos->left == NULL && pos->right == NULL) {
            if(isleft) return pos->val;
            return 0;
        }
        int sum = 0;
        sum += call(pos->left, 1);
        sum += call(pos->right, 0);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return call(root, 0);
    }
};
