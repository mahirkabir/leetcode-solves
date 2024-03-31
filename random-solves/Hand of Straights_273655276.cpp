class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int sz = hand.size();
        if(sz % W != 0)
            return false;
        
        map<int, int> mp;
        for(int i = 0; i < sz; ++i)
            mp[hand[i]]++;
        
        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            int start = it->first;
            
            while(mp[start] > 0) {
                for(int i = start; i < start + W; ++i) {
                    if(mp[i] > 0) {
                        mp[i]--;
                    }
                    else {
                        cout << i << endl; 
                        return false;
                    }
                }   
            }
        }
        
        return true;
    }
};
