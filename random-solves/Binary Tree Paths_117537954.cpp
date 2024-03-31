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
    vector<string> Path;
    
    string toString(int num) {
        bool neg = false;
        
        if(num < 0) {
            neg = true;
            num = -num;
        }
        
        string ret = "";
        
        while(num > 0) {
            ret.push_back((num % 10) + '0');
            num /= 10;
        }
        
        reverse(ret.begin(), ret.end());
        
        if(neg) ret = "-" + ret;
        
        return ret;
    }
    
    void GetPath(TreeNode* curr, string currPath) {
        currPath += "->" + toString(curr->val);
        
        if(curr->left == NULL && curr->right == NULL) {
            Path.push_back(currPath.substr(2));
        }
        else {
            if(curr->left != NULL) GetPath(curr->left, currPath);
            if(curr->right != NULL) GetPath(curr->right, currPath);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        Path.clear();
        if(root == NULL) return Path;
        
        string path = "";
        
        GetPath(root, "" + path);
        return Path;
    }
};
