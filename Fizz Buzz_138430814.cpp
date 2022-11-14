class Solution {
public:
    string s, itoa(int n) {
        s.clear();
        
        while(n > 0) {
            s.push_back((n % 10) + '0');
            n /= 10;
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
    
    vector<string> v, fizzBuzz(int n) {
        for(int i = 1; i <= n; ++i) {
            if(i % 15 == 0)
                v.push_back("FizzBuzz");
            else if(i % 5 == 0)
                v.push_back("Buzz");
            else if(i % 3 == 0)
                v.push_back("Fizz");
            else 
                v.push_back(itoa(i));
        }
        
        return v;
    }
};
