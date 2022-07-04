class Solution:
    def leadsToDestination(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        # Creating the graph
        g = [set() for _ in range(n)]
        for edge in edges:
            g[edge[0]].add(edge[1])
        
        # destination should not point to any other node
        if len(g[destination]) > 0:
            return False

        seen = set()
        
        def dfs(node):
            # If can't reach any other node, node has to be destination
            if len(g[node]) == 0:
                return node == destination

            for neighborg in g[node]:
                if neighborg in seen:
                    # Cycle Found!!!
                    return False
                
                seen.add(neighborg)
                if not dfs(neighborg):
                    # We stop if the path could not reach destination
                    return False
                seen.remove(neighborg)
            
            # Congratulations all paths reaches destination
            return True
        
        return dfs(source)