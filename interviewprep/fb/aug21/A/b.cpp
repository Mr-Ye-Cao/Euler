class NumMatrix {
public:
    int m;
    int n;
    vector<vector<int> > mat;
    
    NumMatrix(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        
        mat.resize(m);
        mat[0].resize(n);
        mat[0][0]=matrix[0][0];
        
        for(int i=1;i<n;i++)
            mat[0][i]=mat[0][i-1]+matrix[0][i];
        for(int i=1;i<m;i++)
            mat[i].push_back(mat[i-1][0]+matrix[i][0]);
        
        for(int i=1;i<m;i++){
            mat[i].resize(n);
            for(int j=1;j<n;j++){
    mat[i][j]=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1==0&&col1==0)
            return mat[row2][col2];
        
        if(row1==0){
            return mat[row2][col2]-mat[row2][col1-1];
        }
        
        if(col1==0){
            return mat[row2][col2]-mat[row1-1][col2];
        }
        
        return mat[row2][col2]-mat[row1-1][col2]-mat[row2][col1-1]+mat[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */