class Solution {
public:
    int mp[200000 + 5];
    
    int hash(int n) {
        return n + 100000;
    }
    
    int distributeCandies(vector<int>& v) {
        int n = v.size();
        
        int type = 0;
        
        for(int i = 0; i < n; ++i) {
            if(mp[hash(v[i])] == 0) {
                type++;
            }
            
            mp[hash(v[i])]++;
        }
        
        if(type <= (n >> 1))
            return type;
        
        return n >> 1;
    }
};
