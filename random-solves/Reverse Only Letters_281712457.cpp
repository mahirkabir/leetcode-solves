class Solution {
public:
    bool isAlpha(char ch) {
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
    }
    
    string reverseOnlyLetters(string str) {
        int n = str.length();
        
        vector<char> v;
        for(int i = 0; i < n; ++i) {
            if(isAlpha(str[i]))
                v.push_back(str[i]);
        }
        
        for(int i = 0, it = v.size(); i < n; ++i) {
            if(isAlpha(str[i]))
                str[i] = v[--it];
        }
        
        return str;
    }
};
