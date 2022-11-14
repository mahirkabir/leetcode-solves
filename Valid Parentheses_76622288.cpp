class Solution {
public:
    bool isValid(string str) {
        int n = str.length();
        stack <char> s;
        for(int i = 0; i < n; ++i) {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[') s.push(str[i]);
            else {
                if(s.empty()) return false;
                char ch = s.top();
                if(str[i] == ')' && ch == '(') s.pop();
                else if(str[i] == ']' && ch == '[') s.pop();
                else if(str[i] == '}' && ch == '{') s.pop();
                else return false;
            }
        }
        return s.empty();
    }
};
