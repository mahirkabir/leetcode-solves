/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right
     (right) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(vector<long long> v) {
        int n = v.size();
        
        for(int i = 0, j = n - 1; i < j; ++i, --j) {
            if(v[i] != v[j])
                return false;
        }
        
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        const long long MAX = (long long)INT_MAX + 1;
        vector<long long> track[50];
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        
        int mxLevel = 0;
        
        while(!q.empty()) {
            pair<TreeNode*, int> u = q.front();
            q.pop();
            
            int level = u.second;
            mxLevel = max(level, mxLevel);
            
            if(u.first != NULL)
                track[level].push_back(u.first->val);
            else
                track[level].push_back(MAX);
                
            if(u.first != NULL) {
                q.push(make_pair(u.first->left, level + 1));
                q.push(make_pair(u.first->right, level + 1));
            }
        }
        
        for(int i = 0; i <= mxLevel; ++i) {
            if(!isPalindrome(track[i]))
                return false;
        }
        
        return true;
    }
};
