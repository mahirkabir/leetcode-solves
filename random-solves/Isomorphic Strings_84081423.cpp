class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        map <char, char> mp, flag;
        for(int i = 0; i < n; ++i) {
            if(mp[s[i]] || flag[t[i]]) {
                if(mp[s[i]] != t[i]) return false;
            }
            mp[s[i]] = t[i];
            flag[t[i]] = true;
        }
        return true;
    }
};
