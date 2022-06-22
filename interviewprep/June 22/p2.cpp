class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // bellman-ford dynamic programming algorithm
        // single source all targets

        k--;

        for(int i=0;i<times.size();i++){
            times[i][0]--;
            times[i][1]--;
        }

        vector<int> dist(n,INT_MAX);

        dist[k] = 0;

        // Step 2: Relax all edges |V| - 1 times. A simple
        // shortest path from src to any other vertex can have
        // at-most |V| - 1 edges
        for (int i = 1; i <= n - 1; i++) {
            for (int j = 0; j < times.size(); j++) {
                int u = times[j][0];
                int v = times[j][1];
                int weight = times[j][2];
                if (dist[u] != INT_MAX
                    && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }

        int res=INT_MIN;
        for(int i=0;i<dist.size();i++)
            res=max(res, dist[i]);
        
        if(res==INT_MAX){
            return -1;
        }
        return res;
    }
};