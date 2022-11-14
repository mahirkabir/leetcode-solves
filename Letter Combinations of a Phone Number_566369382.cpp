class Solution {
public:
    map<int, vector<char>> mp;
    vector<string> result;
    string digits;
    int len;
    
    void generateCombinations(int idx, int pos, string str) {
        if (idx == len) {
            result.push_back(str);
            return;
        }
        
        if (pos >= mp[digits[idx]].size())
            return;
        
        generateCombinations(idx, pos + 1, str);
        str.push_back(mp[digits[idx]][pos]);
        generateCombinations(idx + 1, 0, str);    }
    
    vector<string> letterCombinations(string _digits) {
        mp.clear();
        vector<char> alphabets;
        digits = _digits;
        len = digits.length();
        
        if (len == 0)
            return result;
        
        for (char ch = 'a'; ch <= 'z'; ch++) {
            alphabets.push_back(ch);
        }
        
        int it = 0;
        for (int i = 2; i <= 9; ++i) {
            int cnt = 3;
            if (i == 7 || i == 9)
                cnt = 4;
            while(cnt-- > 0)
                mp[i + '0'].push_back(alphabets[it++]);
        }
        
        generateCombinations(0, 0, "");
            
        return result;
    }
};
