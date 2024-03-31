class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string res = "";
        int mxln = 0, st = 0, en = 0;
        
        for(int i = 0; i < n; ++i) {
            //even string
            int curr = 0;
            int j = i-1, k = i;
            for(; j >= 0 && k < n;) {
                if(s[j] == s[k]) {
                    curr += 2;
                    j--;
                    k++;
                }
                else {
                    break;
                }
            }
            if(mxln < curr) {
                mxln = curr;
                st = j+1;
                en = k-1;
            }
            
            //odd string with i at center
            curr = 1;
            j = i-1, k = i+1;
            for(; j >= 0 && k < n;) {
                if(s[j] == s[k]) {
                    curr += 2;
                    j--;
                    k++;
                }
                else {
                    break;
                }
            }
            if(mxln < curr) {
                mxln = curr;
                st = j+1;
                en = k-1;
            }
        }
        
        return s.substr(st, (en-st+1));
    }
};
