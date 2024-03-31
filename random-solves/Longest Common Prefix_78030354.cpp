class Solution {
public:
    string getMinString(vector <string> v) {
        int pos = 0;
        int n = v.size();
        int ln = v[pos].length();
        for(int i = 1; i < n; ++i) {
            if(v[i].size() > ln) {
                ln = v[i].size();
                pos = i;
            }
        }
        return v[pos];
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string res = getMinString(strs);
        int n = strs.size();
        int pos = res.length() - 1;
        for(int i = 0; i < n; ++i) {
            int it = 0;
            while(pos >= 0 && it <= pos && res[it] == strs[i][it]) it++;
            if(res[it] != strs[i][it] && pos >= 0) pos = it - 1;
        }
        if(pos < 0) return "";
        return res.substr(0, pos + 1);
    }
};
