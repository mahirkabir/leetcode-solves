class Solution {
public:
    queue<pair<pair<int, int>, int>> firstIslanders;
    int row;
    int col;
    
    int shortestBridge(vector<vector<int>>& A) {
        while(!firstIslanders.empty())
            firstIslanders.pop();
        row = A.size();
        col = A[0].size();
        bool flag = false;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(A[i][j] == 1) {
                    DFS(A, i, j);
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        
        /*for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                cout << A[i][j] << " ";
            }
            
            cout << endl;
        }*/
        
        return BFS(A);
    }
    
    void DFS(vector<vector<int>>& A, int i, int j) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        A[i][j] = 2;
        //cout << "Pushing in firstIslanders" << endl;
        firstIslanders.push(make_pair(make_pair(i, j), 0));
        
        for(int di = 0; di < 4; ++di) {
            int newX = i + dx[di];
            int newY = j + dy[di];
            
            //cout << i << " " << j << " " << newX << " " << newY << " " << A[i][j] 
                << endl;     
            
            if(newX >= 0 && newY >= 0 && newX < row && newY< col && A[newX][newY] == 
                1) {
                DFS(A, newX, newY);
            }
        }
    }
    
    int BFS(vector<vector<int>> &A) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int cnt = 0;
        
        while(!firstIslanders.empty()) {
            pair<pair<int, int>, int> p = firstIslanders.front();
            firstIslanders.pop();
            
            //cout << p.first.first << " " << p.first.second << " " << p.second << 
                endl;
            
            for(int di = 0; di < 4; ++di) {
                int newX = p.first.first + dx[di];
                int newY = p.first.second + dy[di];
                if(newX >= 0 && newY >= 0 && newX < row && newY < col && 
                    A[newX][newY] != 2) {
                    if(A[newX][newY] == 1) {
                        //cout << p.second << endl;
                        return p.second;
                    }
                    else if(A[newX][newY] == 0) {
                        A[newX][newY] = 2;
                        firstIslanders.push(make_pair(make_pair(newX, newY), p.second 
                            + 1));
                    }
                }
            }
        }
        
        return cnt;
    }
};
