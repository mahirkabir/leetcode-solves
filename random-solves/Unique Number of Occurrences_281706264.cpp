class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        
        int n = arr.size();
        
        for(int i = 0; i < n; ++i)
            mp[arr[i]]++;
        
        arr.clear();
        
        for(map<int, int>:: iterator it = mp.begin(); it != mp.end(); it++)
            arr.push_back(it->second);
        
        sort(arr.begin(), arr.end());
        
        n = arr.size();
        
        for(int i = 0; i < n -1; ++i)
            if(arr[i] == arr[i + 1])
                return false;
        
        return true;
    }
};
