class Solution:
    def DFS(self, u, edge, color):
        # print(u, "u")
        color[u] = 1
        
        if u in edge:
            for v in edge[u]:
                if v in color and color[v] == 1:
                    # print(v, {})
                    return {}
                elif v not in color or color[v] == 0:
                    color = self.DFS(v, edge, color)
                    if len(color) == 0:
                        return color
        
        color[u] = 2
        # print(color)
        return color
    
    def canFinish(self, n: int, pre: List[List[int]]) -> bool:
        if len(pre) == 0:
            return True
        
        edge = {}
        in_nodes = {}
        for p in pre:
            u, v = p[1], p[0]
            if u not in edge:
                edge[u] = []
            edge[u].append(v)
            
            if v in edge and u in edge[v]:
                return False
            
            if v not in in_nodes:
                in_nodes[v] = 0
            in_nodes[v] += 1
            
        color = {}
        for s in range(n):
            # print(s, s in in_nodes, "check")
            if s not in in_nodes:
                # print(s, "starts")
                # Process only for nodes that are independent
                color = self.DFS(s, edge, color)
                if len(color) == 0:
                    return False
                # print(s, "ends")
    
        # print(in_nodes, "in_nodes")
        for s in range(n):
            if s not in color:
                # print(s, color, [])
                return False
        return True
