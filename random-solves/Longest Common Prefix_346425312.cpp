class Solution {
public:
    string getMinString(vector<string>& v) {
        int sz = v.size();
        
        int shortestIdx = 0;
        int shortestLen = v[0].length();
        
        for(int i = 1; i < sz; ++i) {
            int n = v[i].length();
            
            if(n < shortestLen) {
                shortestLen = n;
                shortestIdx = i;
            }
        }
        
        return v[shortestIdx];
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        
        string pre = getMinString(strs);
        int prepos = pre.length() - 1;
        
        // cout << pre << " " << prepos << endl;
        
        int sz = strs.size();
        for(int i = 0; i < sz; ++i) {
            
            string str = strs[i];
            int n = str.length();
            
            int len = min(prepos, n - 1);
            
            // cout << len << endl;
            
            for(int j = 0; j <= len; ++j) {
                
                if(str[j] != pre[j]) {

                    // cout << str << " " << pre << endl;
                    // cout << str[j] << " ~ " << pre[j] << endl;
                    
                    int popcnt = prepos - j + 1;
                    
                    while(popcnt-- > 0)
                        pre.pop_back();

                    if(prepos != -1)
                        prepos = j - 1;
                    
                    // cout << prepos << endl;
                    break;
                }
            }
        }
        
        return pre;
    }
};
