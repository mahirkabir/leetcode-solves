class Solution {
public:
    bool isAnagram(string s, string t) {
        int sn = s.length(), st = t.length();
        if(sn != st) return false;
        int arr[26];
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < sn; ++i) arr[s[i] - 'a']++, arr[t[i] - 'a']--;
        for(int i = 0; i < 26; ++i) if(arr[i] != 0) return false;
        return true;
    }
};
