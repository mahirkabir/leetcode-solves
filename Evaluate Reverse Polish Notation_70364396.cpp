class Solution {
public:
    int toInt(string str) {
        int n = str.length();
        int ret = 0;
        int st = 0;
        if(str[0] == '-') {
            st++;
        }
        for( int i = st; i < n; ++i ) {
            ret = ret*10 + str[i]-'0';
        }
        return (st == 0)?ret:-ret;
    }
    bool isOperator( string str ) {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }
    string toStr( int n ) {
        string str = "";
        int sign = (n < 0)?-1:1;
        n = (n > 0)?n:-n;
        while(n) {
            str.push_back(n%10 + '0');
            n /= 10;
        }
        reverse(str.begin(), str.end());
        if(sign == -1) str = "-" + str;
        return str;
    }
    int getRes( string l, string r, string op ) {
        if( op == "+" ) {
            return toInt(l) + toInt(r);
        }
        else if( op == "-" ) {
            return toInt(l) - toInt(r);
        }
        else if( op == "*" ) {
            return toInt(l) * toInt(r);
        }
        else {
            return toInt(l) / toInt(r);
        }
    }
    int evalRPN(vector<string>& tokens) {
        vector<string> A = tokens;
        stack < string > s;
        int sz = A.size();
        for( int i = 0; i < sz; ++i ) {
            if(isOperator(A[i])) {
                string r = s.top();
                s.pop();
                string l = s.top();
                s.pop();
                int evaluate = getRes(l, r, A[i]);
                s.push(toStr(evaluate));
            }
            else {
                s.push(A[i]);
            }
        }
        return toInt(s.top());
    }
};
