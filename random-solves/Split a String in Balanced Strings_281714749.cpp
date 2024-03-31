class Solution {
public:
    int balancedStringSplit(string str) {
        stack<char> s;
        
        int n = str.length();
        
        int ans = 0;
        
        s.push(str[0]);
        
        for(int i = 1; i < n; ++i) {
            if(s.top() == str[i])
                s.push(str[i]);
            else 
                s.pop();
            
            if(s.empty()) {
                ++ans;
                s.push(str[++i]);
            }
        }
        
        return ans;
    }
};
