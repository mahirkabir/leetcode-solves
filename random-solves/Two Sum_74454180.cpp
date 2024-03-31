class Solution {
public:
    #define SZ 1000
    vector <int> v[SZ+5], pos[SZ+5];
    
    int hashCode(int a) {
        return abs(a)%SZ;
    }
    void insert(int a, int p) {
        int idx = hashCode(a);
        v[idx].push_back(a);
        pos[idx].push_back(p);
    }
    int find(int a) {
        int idx = hashCode(a);
        int n = v[idx].size();
        for(int i = 0; i < n; ++i) if(v[idx][i] == a) return pos[idx][i];
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector <int> ret;
        for(int i = 0; i < n; ++i) {
            int lookUp = find(target - nums[i]);
            if(lookUp == -1) insert(nums[i], i);
            else {
                ret.push_back(lookUp);
                ret.push_back(i);
                break;
            }   
        }
        return ret;
    }
};
