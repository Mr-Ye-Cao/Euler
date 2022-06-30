class Solution {
    
    class Pair{
        int x;int y;
        Pair(int x,int y){
            this.x=x;
            this.y=y;
        }
    }
    
	//All primary neighbours
    static int dir[][] = {
        {-1,1},
        {-1,0},
        {-1,-1},
        {0,1},
        {0,-1},
        {1,1},
        {1,0},
        {1,-1},
        {-1,2},
        {-2,1},
        {-2,-1},
        {-1,-2},
        {1,2},
        {2,1},
        {1,-2},
        {2,-1}
    };
        
	//Secondary neighbours which become active when primary are inactive
    static int exDir[][]={
        {-2,2},
        {-2,0},
        {-2,-2},
        {0,2},
        {0,-2},
        {2,2},
        {2,0},
        {2,-2}
    };
    
    int result=0;
    int m=0;
    int n=0;
    boolean [][] arr;
    public int numberOfPatterns(int m, int n) {
        arr = new boolean[3][3];
        this.m=m;
        this.n=n;
        
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                Pair p = new Pair(i,j);
                utils(p,0);        
            }
        
        return result;
    }
    
    
    private void utils(Pair p,int len){
        arr[p.x][p.y]=true;
        len++;
        if(len>=m && len<=n)
            result++;
        
        if(len<n){
            for(Pair nb:getNeighbours(p)){
                utils(nb,len);
            }
        }
        
        arr[p.x][p.y]=false;
    }
    
    public List<Pair> getNeighbours(Pair p){
        List<Pair> result = new ArrayList<>();

        
        for(int i=0;i<dir.length;i++){
            int x = p.x + dir[i][0];
            int y = p.y + dir[i][1];
            if(x<3 && x>=0 && y<3 && y>=0)
                if(!arr[x][y]){
                    result.add(new Pair(x,y));
                }else if(i<exDir.length){
                          x = p.x + exDir[i][0];
                          y = p.y + exDir[i][1];
                        if(x<3 && x>=0 && y<3 && y>=0)
                            if(!arr[x][y]){
                                result.add(new Pair(x,y));
                    }
                }
        }
        
        return result;
    }
    
}