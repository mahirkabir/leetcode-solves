class Solution {
public:
    string reverseString(string s) {
         int n = s.length();
         string ret = "";
         for( int i = n-1; i >= 0; --i ) ret.push_back(s[i]);
         return ret;
    }
};
