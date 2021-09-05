class Solution {
public:
    
    vector<vector<int> > dir = {{1,0},{0,1},{-1,0},{0,-1}};
        
    bool inside(int x,int y,int xs,int ys){
        return x>=0 && y>=0 && x<xs && y<ys;
    }
        
    bool dfs(vector<vector<int>>& grid,int x,int y){
        if(!inside(x,y,grid.size(),grid[0].size()))
            return false;
        if(grid[x][y]==1)
            return true;
        
        grid[x][y]=1;
        
        bool val=true;
        for(auto p: dir){
            val&=dfs(grid,x+p[0],y+p[1]);
        }
        
        return val;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==0)
                    if(dfs(grid,i,j))
                        ans++;
        
        return ans;
    }
};