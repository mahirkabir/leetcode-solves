class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0, even = 0;
        
        int n = chips.size();
        
        for(int i = 0; i < n; ++i)
            odd += (chips[i] % 2), even += (chips[i] % 2 == 0);
        
        return min(odd, even);
    }
};
