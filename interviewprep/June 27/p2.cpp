class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        
        // let (i,j) be the top left point of the square
        // then the answer must be one of the (i,j)

        vector<vector<int> > dp(m, vector<int> (n, 0));

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                // base case top left corner contains 0
                if(matrix[i][j]=='0'){
                    continue;
                }
                if(i==m-1 || j==n-1){
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j]=1;

                int cbn1=sqrt(dp[i+1][j]),cbn2=sqrt(dp[i][j+1]),cbn3=sqrt(dp[i+1][j+1]);
                dp[i][j]=max(dp[i][j],(min(min(cbn1,cbn2)+1,cbn3+1))*(min(min(cbn1,cbn2)+1,cbn3+1)));
            }
        }

        int result=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result=max(dp[i][j],result);
            }
        }

        return result;
    }
};