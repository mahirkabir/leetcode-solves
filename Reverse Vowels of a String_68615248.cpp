class Solution {
public:
    bool isVowel( char ch ) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 
            'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
    string reverseVowels(string s) {
        vector < char > v;
        int n = s.length();
        for( int i = 0; i < n; ++i ) 
            if(isVowel(s[i])) 
                v.push_back(s[i]);
        string ret = "";
        for( int i = 0, j = v.size()-1; i < n; ++i ) {
            if(isVowel(s[i])) {
                ret.push_back(v[j--]);
            }
            else {
                ret.push_back(s[i]);
            }
        }
        return ret;
    }
};
