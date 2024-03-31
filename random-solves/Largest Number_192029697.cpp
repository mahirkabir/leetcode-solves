string toString(int n) {
    string str = "";
    while(n > 0) {
        str.push_back((n % 10) + '0');
        n /= 10;
    }

    if(str == "")
        return "0";

    reverse(str.begin(), str.end());

    return str;
}


bool cmp(int a, int b) {
    string sa = toString(a);
    string sb = toString(b);
    
    return sa + sb > sb + sa;
}

class Solution {
public:
    
    string join(vector<int> nums) {
        string str = "";

        int n = nums.size();
        for(int i = 0; i < n; ++i)
            str += toString(nums[i]);

        if(str[0] == '0')
            str = "0";
        
        return str;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        return join(nums);
    }
};
