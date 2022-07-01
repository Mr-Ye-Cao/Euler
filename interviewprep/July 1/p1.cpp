class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();

        map<int,int> d;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(d.find(j-i)==d.end()){
                    d[j-i]=matrix[i][j];
                }else{
                    if(d[j-i]!=matrix[i][j]){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};