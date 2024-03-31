class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        int cnt = r * c;
        int right = c - 1;
        int down = r - 1;
        int left = 0;
        int up = 1;
        
        int i = 0;
        int j = 0;
        while(cnt > 0) {
            // go right
            while(j <= right && cnt > 0) {
                ans.push_back(matrix[i][j++]);
                cnt--;
            }
                
            right -= 1;
            i++;
            j--;
            
            
            // go down
            while(i <= down && cnt > 0) {
                ans.push_back(matrix[i++][j]);
                cnt--;
            }
            down -= 1;
            i--;
            j--;
            
            // go left
            while(j >= left && cnt > 0) {
                ans.push_back(matrix[i][j--]);
                cnt--;
            }
            left += 1;
            i--;
            j++;
            
            // go up
            while(i >= up && cnt > 0) {
                ans.push_back(matrix[i--][j]);
                cnt--;
            }
            up += 1;
            i++;
            j++;
        }
        
        return ans;
    }
};
