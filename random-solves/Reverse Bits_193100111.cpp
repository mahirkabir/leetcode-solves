#define ui uint32_t

class Solution {
public:
    string trim(string str) {
        string ret = "";

        int n = str.length();

        for(int i = 0; i < n; ++i) {
            if(str[i] == '1') {
                ret.push_back(str[i]);
            }
            else if(ret != "") {
                ret.push_back(str[i]);
            }
        }

        return ret;
    }

    string pad32(string str) {
        int n = str.length();
        n = 32 - n;

        while(n--)
            str.push_back('0');

        return str;
    }

    string toStringRev(ui n) {
        string str = "";

        while(n > 0) {
            str.push_back(n % 2 + '0');
            n >>= 1;
        }

        return pad32(str);
    }

    ui toUI(string str) {
        if(str == "" || str[0] == '0')
            return 0;

        ui ret = 0;

        int n = str.length();
        for(int i = 0; i < n; ++i) {
            ret <<= 1;
            ret += (str[i] == '1');
        }

        return ret;
    }
    
    uint32_t reverseBits(uint32_t n) {
        return toUI(trim(toStringRev(n)));
    }
};
