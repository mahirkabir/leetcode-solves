class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int prevOcc[205];
        memset(prevOcc, -1, sizeof(prevOcc));
        int startingPoint = 0, ans = 0, curr = 0;
        
        for(int i = 0; i < n; ++i) {
            if(prevOcc[s[i]] < startingPoint) {
                prevOcc[s[i]] = i;
                curr++;
            }
            else {
                startingPoint = prevOcc[s[i]] + 1;
                ans = max(ans, curr);
                curr = (i - startingPoint + 1);
                prevOcc[s[i]] = i;
            }
        }
        
        ans = max(ans, curr);
        return ans;
    }
};
