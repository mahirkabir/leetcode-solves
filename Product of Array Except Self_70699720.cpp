class Solution {
public:
    
    vector<int> v, productExceptSelf(vector<int>& nums) {
        int z = 0, idx = -1;
        int sz = nums.size();
        int tmp = 1;
        for( int i = 0; i < sz; ++i ) {
            if(nums[i] == 0) {
                z++;
                idx = i;
            }
            else {
                tmp *= nums[i];
            }
        }
        if(z >= 1) {
            for(int i = 0; i < sz; ++i) {
                if( i == idx && z == 1 ) {
                    v.push_back(tmp);
                }
                else {
                    v.push_back(0);
                }
            }
            return v;
        }
        
        long long m = 1;
        
        for( int i = 1; i < sz; ++i ) m*= nums[i];
        v.push_back(m);
        for( int i = 1; i < sz; ++i ) {
            /*if(nums[i] == 1 ) {
                v.push_back(v[i-1]*(nums[i-1]));
            }
            else {
                v.push_back( v[i-1]*(nums[i-1]) - v[i-1]*(nums[i-1])*(nums[i]-1) );
            }*/
            v.push_back(v[i-1]*(nums[i-1])*pow(nums[i],-1));
        }
        return v;
    }
};
