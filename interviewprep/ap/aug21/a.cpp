class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int> > res;
        res.resize(n);
        for(int i=0;i<n;i++)
            res[i].resize(m);
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                res[j][i]=matrix[i][j];
        
        return res;
    }
};