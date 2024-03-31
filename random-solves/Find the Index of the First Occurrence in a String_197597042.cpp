class Solution {
public:
    int strStr(string s, string a) {
        if(a == "")
            return 0;
        
        int sn = s.length();
        int an = a.length();
        
        for(int i = 0; i < sn; ++i) {
            int cnt = 0;
            for(int j = i, k = 0; j < i + an && j < sn; ++j, ++k) {
                if(s[j] != a[k])
                    break;
                else
                    cnt++;
            }
            if(cnt == an)
                return i;
        }
        
        return -1;
    }
};
