class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {

        int x = rowSum.size();
        int y = colSum.size();

        vector<vector<int>> ans(x,vector<int>(y));


        int i=0,j=0;

        while(i<x and j<y)
        {
            int z = min(rowSum[i],colSum[j]);
            ans[i][j]=z;
            rowSum[i]-=z;
            colSum[j]-=z;
            if(rowSum[i]==0)i++;
            if(colSum[j]==0)j++;
        }

        return ans;

    }
};