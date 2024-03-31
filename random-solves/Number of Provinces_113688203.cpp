
class Solution {
public:
    int color[205];
    int n;
    vector <vector <int>> adj;
    
    void DFS(int s) {
        color[s] = 1;
        for(int i = 0; i < n; ++i) {
            if(adj[s][i] == 1 && color[i] == 0) {
                DFS(i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        adj = M;
        M.clear();
        
        if(adj.empty()) return 0;
        
        n = adj[0].size();    
        int circle = 0;
        
        color[205];
        memset(color, 0, sizeof(color));
        
        for(int i = 0; i < n; ++i) {
            if(color[i] == 0) {
                circle++;
                DFS(i);
            }
        }
        
        return circle;
    }
};
