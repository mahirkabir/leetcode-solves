class Solution:
    def DFS(self, node, edge, visited, dp):
        print(node, "entering DFS")
        if node in dp:
            return dp[node]
        
        if node in visited and visited[node] == 1:
            return False
        
        visited[node] = 1
        
        if node in edge:
            for neigh in edge[node]:
                # print(neigh, "inside loop")
                if self.DFS(neigh, edge, visited, dp) == False:
                    return False
        
        visited[node] = 2
        
        dp[node] = True
        return dp[node]
    
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if len(prerequisites) == 0:
            return True
        
        edge = {}
        for pre in prerequisites:
            a, b = pre[0], pre[1]
            if b not in edge:
                edge[b] = [a]
            else:
                edge[b].append(a)
        
        dp = {}
        for node in edge:
            if self.DFS(node, edge, {}, dp) == False:
                return False
        
        return True
