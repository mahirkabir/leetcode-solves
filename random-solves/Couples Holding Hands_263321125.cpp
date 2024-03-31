class Solution {
public:
    int getPartner(int id) {
        return id % 2 == 0 ? id + 1 : id - 1;
    }
    
    int areInSameBlock(int selfPosition, int partnerPosition) {
        return selfPosition / 2 == partnerPosition / 2;
    }
    
    int getSuitablePosition(int partnerPosition) {
        return partnerPosition % 2 == 0 ? partnerPosition + 1 : partnerPosition - 1;
    }
    
    void process(vector<int> &row, map<int, int> &mp, int position, int &ans) {
        int partner = getPartner(row[position]);
        if(mp[partner]) {
            if(!areInSameBlock(position, mp[partner])) {
                int suitablePosition = getSuitablePosition(mp[partner]);
                
                int t = row[suitablePosition];
                row[suitablePosition] = row[position];
                row[position] = t;
                
                mp[t] = position;
                
                ans++;
                
                process(row, mp, position, ans);
            }
        }
        else {
            mp[row[position]] = position;
        }
    }
    
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();

        map<int, int> mp;
        int ans = 0;
        
        for(int i = 0; i < n; ++i) {
            process(row, mp, i, ans);
        }
        
        return ans;
    }
};
