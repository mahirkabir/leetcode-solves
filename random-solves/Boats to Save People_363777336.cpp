class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int n = people.size();
        int cnt = 0;
        int taken = 0;
        
        int st = 0, en = n - 1;
        
        while(taken < n) {
            if(people[st] + people[en] <= limit) {
                cnt++;
                taken += 2;
                st++;
                en--;
            } else {
                cnt++;
                en--;
                taken++;
            }
        }
        
        return cnt;
    }
};
