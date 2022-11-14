class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int f = 0, l = numbers.size() - 1;
        
        while(f < l) {
            //cout << f << " " << l << " " <<  numbers[f] << " " << numbers[l] << 
                endl;
            if( numbers[f] + numbers[l] == target ) break;
            if( numbers[f] + numbers[l] > target ) l--;
            else f++;
        }
        
        vector <int> ret;
        ret.push_back(f + 1);
        ret.push_back(l + 1);
        return ret;
    }
};
