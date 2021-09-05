class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool tocont=true;
        int n=graph.size();
        
        vector<int> status(n,0);
        
        // BFS
        
        queue<int> bf;
        bf.push(0);
        status[0]=1;
        
        while(tocont){
            tocont=false;
            while(!bf.empty()){
                int tovis=bf.front();
                bf.pop();
                for(int neighbor:graph[tovis]){
                    if(status[neighbor]==0){
                        bf.push(neighbor);
                        status[neighbor]=-status[tovis];
                    }else{
                        if(status[neighbor]==status[tovis]){
                            return false;
                        }
                    }
                }
            }
            for(int i=0;i<n;i++){
                if(status[i]==0){
                    bf.push(i);
                    status[i]=1;
                    tocont=true;
                    break;
                }
            }
        }
        
        return true;
    }
};