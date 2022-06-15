class Solution {
public:
    int minReorder(int n, vector<vector<int>>& graph) {
        unordered_map<int,vector<int>> neighbors;
        set<pair<int,int>> edge_look_up;

        for(int i =0 ;i <graph.size();i++){
            neighbors[graph[i][0]].push_back(graph[i][1]);
            neighbors[graph[i][1]].push_back(graph[i][0]);            
            edge_look_up.insert({graph[i][0],graph[i][1]});
        }
        
        
        queue<int> q ;
        unordered_set<int> seen;
        q.push(0);
        seen.insert(0);
        int moves =0 ;
        while(!q.empty()) {
            int city = q.front();q.pop();
            for(int neighbor : neighbors[city]) {
                if (seen.find(neighbor)!=seen.end()) continue;
                
                if (edge_look_up.find({neighbor,city}) == edge_look_up.end()) {
                  moves++;   
                }
                q.push(neighbor);
                seen.insert(neighbor);
            }
        }
        return moves;
    }
};