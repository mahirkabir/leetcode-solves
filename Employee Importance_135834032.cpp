/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/

int color[2000 + 5];
stack<int> s;
Employee* mp[2000 + 5];

class Solution {
public:
    int getImportance(vector<Employee*> v, int id) {
        int n = v.size();
        
        while(!s.empty()) s.pop();
        
        for(int i = 0; i < n; ++i) {
            mp[v[i]->id] = v[i];
            color[v[i]->id] = 0;
        }
            
        
        s.push(id);
        
        int tot = 0;
        
        while(!s.empty()) {
            int u = s.top(); s.pop();
            color[u] = 1;
            
            tot += mp[u]->importance;
            
            int sz = mp[u]->subordinates.size();
            
            for(int i = 0; i < sz; ++i) {
                int v = mp[u]->subordinates[i];
                
                if(color[v] == 0) {
                    s.push(v);
                }
            }
            
            color[u] = 2;
            
        }
        
        return tot;
    }
};
