class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        
        int mx = max(a.length(), b.length());
        int j = mx - a.length() + 1;
        while(j--) a = "0" + a;
        j = mx - b.length() + 1;
        while(j--) b = "0" + b;
        bool add = false;
        for(int i = mx; i >= 0; --i) {
            bool first  = (a[i] == '1')?true:false;
            bool second = (b[i] == '1')?true:false;
            if(first && second) {
                if(add) {
                    ret.push_back('1');
                }
                else {
                    ret.push_back('0');
                    add = true;
                }
            }
            else if(first || second) {
                if(add) {
                    ret.push_back('0');
                }
                else {
                    ret.push_back('1');
                }
            }
            else {
                if(add) {
                    ret.push_back('1');
                    add = false;
                }
                else {
                    ret.push_back('0');
                }
            }
        }
        if(add) ret.push_back('1');
        if(ret[ret.length()-1] == '0' && ret.length() > 1) ret.pop_back();
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
