class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, en = s.length() - 1;
        
        while(st < en) {
            while(!isalnum(s[st]) && st < en) st++;
            while(!isalnum(s[en]) && st < en) en--;
            
            char a = tolower(s[st]);
            char b = tolower(s[en]);
            
            if(a != b)
                return false;
            
            st++;
            en--;
        }
        
        return true;
    }
};
