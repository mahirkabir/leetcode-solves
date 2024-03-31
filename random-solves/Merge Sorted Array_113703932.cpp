class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0) {
            nums1 = nums2;
            return;
        }
        if(n == 0) return;
        
        int itm = 0, itn = 0;
        int cnt = m + n;
        
        vector <int> res;
        
        while(cnt--) {
            if(itm == m) {
                res.push_back(nums2[itn++]);
            }
            else if(itn == n) {
                res.push_back(nums1[itm++]);
            }
            else if(nums1[itm] < nums2[itn]) {
                res.push_back(nums1[itm++]);
            }
            else {
                res.push_back(nums2[itn++]);
            }
        }
        
        nums1 = res;
    }
};
