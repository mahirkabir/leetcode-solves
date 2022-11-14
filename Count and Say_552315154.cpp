class Solution {
public:
    string toStr(int n) {
        string str = "";
        if (n == 0)
            str = "0";
        
        while(n > 0) {
            str.push_back('0' + (n % 10));
            n /= 10;
        }
        
        reverse(str.begin(), str.end());
        return str;
    }
    
    string countAndSay(int n) {
        string str = "1";
        
        while(n-- > 1) {
            string curr = "";
            
            str.push_back('.');
            int sz = str.length();
            char prev = str[0];
            int cnt = 0;
            for(int i = 0; i < sz; ++i) {
                if(str[i] != prev) {
                    string strCnt = toStr(cnt);
                    curr += strCnt;
                    curr.push_back(prev);
                    if(str[i] == '.') {
                        break;
                    }
                    else {
                        prev = str[i];
                        cnt = 1;
                    }
                }
                else {
                    cnt++;
                }
            }
            
            str = curr;
        }
        
        return str;
    }
};
