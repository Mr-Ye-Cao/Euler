class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if(grid[r][c] < 0)
                    result ++;
            }
        }

        return result;
    }
};