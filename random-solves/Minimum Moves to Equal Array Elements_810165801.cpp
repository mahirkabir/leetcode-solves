class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            s.insert(nums[i]);
            mp[nums[i]] += 1;
        }
        
        int ans = 0;
        set<int>::iterator st = s.begin();
        for (set<int>:: iterator it = s.begin(); it != s.end(); it++) {
            ans += ((*it) - (*st)) * mp[*it];
        }
        
        return ans;
        
    }
};

/*
1   5   8   10  10
+9  +9  +9  +9  0   +9
10  14  17  10  19
+9  +9  +9  +9  0   +9
19  23  26  19  19
+7  +7  +0  +7  +7  +7
26  30  26  26  26
+4  0   +4  +4  +4  +4
30  30  30  30  30
*/

/*
5 6 8
8 9 8
9 9 9
*/
