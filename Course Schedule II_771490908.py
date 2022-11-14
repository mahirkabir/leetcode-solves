class Solution:
    def DFS(self, u, color, edge, ans):
        color[u] = 1
        if u in edge:
            for v in edge[u]:
                # print(u, v)
                if color[v] == 1:
                    return []
                if color[v] == 0:
                    self.DFS(v, color, edge, ans)
        color[u] = 2
        ans.append(u)
        return ans
    
    def findOrder(self, n: int, pre: List[List[int]]) -> List[int]:
        edge = {}
        in_node = {}
        for p in pre:
            u, v = p[1], p[0]
            if u not in edge:
                edge[u] = []
            edge[u].append(v)
            
            if v in edge and u in edge[v]:
                return []
            
            if v not in in_node:
                in_node[v] = 0
            in_node[v] += 1
        
        sources = []
        color = []
        for i in range(n):
            if i not in in_node:
                in_node[i] = 0
                
            if in_node[i] == 0:
                sources.append(i)
            color.append(0)
        
        # print(sources)
        ans = []
        
        for s in range(n):
            if color[s] == 0:
                ans = self.DFS(s, color, edge, ans)
                # print(ans)
        # print(ans)
        if len(ans) == n:
            ans.reverse()
            return ans
        return []
