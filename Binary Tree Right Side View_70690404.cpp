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
    vector <int> v;
    map < int, bool > mp;
    void sideView( TreeNode* curr, int level ) {
        if(!mp[level]) {
            mp[level] = true;
            v.push_back(curr->val);
        }
        if(curr->right != NULL) {
            sideView(curr->right, level+1);
        }
        if(curr->left != NULL) {
            sideView(curr->left, level+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        v.clear();
        mp.clear();
        if(root == NULL) return v;
        sideView(root, 1);
        return v;
    }
};
