class Solution {
public:
    string toLowerCase(string str) {
        int n = str.length();
        
        for(int i = 0; i < n; ++i)
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] - 'A' + 'a';
        
        return str;
    }
};
