class Solution {
public:
    bool isAlphaNum(char ch) {
        return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z');
    }
    void toLower(char *ch) {
        if(*ch >= 'A' && *ch <= 'Z') *ch = *ch - 'A' + 'a';
    }
    bool isPalindrome(string s) {
        int n = s.length();
        if(n <= 1) return true;
        int i = 0, j = n - 1;
        //cout << s << endl;
        while(i < j) {
            toLower(&s[i]);
            toLower(&s[j]);
            //cout << s[i] << " " << s[j] << endl;
            if(isAlphaNum(s[i]) && isAlphaNum(s[j])) {
                if(s[i] == s[j])
                    i++, j--;
                else 
                    return false;
            }
            else {
                if(!isAlphaNum(s[i])) i++;
                if(!isAlphaNum(s[j])) j--;
            }
        }
        return i >= j;
    }
};
