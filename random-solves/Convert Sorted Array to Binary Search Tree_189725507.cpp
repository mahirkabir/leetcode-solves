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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0)
            return NULL;
        
        int mid = n / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        vector<int> vleft(nums.begin(), nums.begin() + mid);
        root->left = sortedArrayToBST(vleft);
        
        vector<int> vright(nums.begin() + mid + 1, nums.begin() + n);
        root->right = sortedArrayToBST(vright);

        return root;
    }
};
