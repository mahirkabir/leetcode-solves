class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, pos = 0;
        int len = nums.size();
        while( j < len ) {
            if( nums[i] == nums[j] ) {
                if( i == j ) {
                    nums[pos++] = nums[i];
                }
                j++;
            }
            else {
                i = j;
            }
        }
        if( pos < len ) nums[pos] = '\0';
        return pos;
    }
};
