class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),answer=0;

        vector<vector<bool>> visted(m, vector<bool> (n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '0'){
                    visted[i][j]=true;
                }
            }
        }

        queue<pair<int,int> > tovisit;
        int previ;
        int prevj;

        while(true){
            for(previ=0;previ<m;previ++){
                for(prevj=0;prevj<n;prevj++){
                    if(!visted[previ][prevj]){
                        tovisit.push(make_pair(previ,prevj));
                        break;
                    }
                }
                if(!tovisit.empty()){
                    break;
                }
            }

            if(tovisit.empty()){
                return answer;
            }

            answer++;

            while(! tovisit.empty()){
                pair<int,int> p=tovisit.front();
                tovisit.pop();
                int x=p.first,y=p.second;
                visted[x][y]=true;

                int xl=x-1,xr=x+1,yu=y-1,yd=y+1;
                
                if(xl>=0){
                    if(!visted[xl][y]){
                        tovisit.push(make_pair(xl,y));
                        visted[xl][y]=true;
                    }
                }

                if(xr<m){
                    if(!visted[xr][y]){
                        tovisit.push(make_pair(xr,y));
                        visted[xr][y]=true;
                    }
                }

                if(yu>=0){
                    if(!visted[x][yu]){
                        tovisit.push(make_pair(x,yu));
                        visted[x][yu]=true;
                    }
                }

                if(yd<n){
                    if(!visted[x][yd]){
                        tovisit.push(make_pair(x,yd));
                        visted[x][yd]=true;
                    }
                }
            }
        }

        return 0;

    }
};