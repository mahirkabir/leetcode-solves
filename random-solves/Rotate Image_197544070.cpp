class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i = 0; i < n / 2; ++i) {
            for(int j = i; j < n - i - 1; ++j) {
                int temp = mat[i][j];
                
                mat[i][j] = mat[n - j - 1][i];
                mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
                mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
                mat[j][n - i - 1] = temp;
            }
        }
        
    }
};

/*
00 02 02
10 11 12
20 21 22

20 10 00
21 11 01
22 12 02

11 = 31
31 = 33
33 = 13
13 = 11

12 = 21
21 = 32
32 = 23
23 = 12

[[7,2,1]
,[4,5,6]
,[9,8,3]]
*/
