class Solution {
public:
    int dp[10001];
    vector<int> sq;

    int helper(int n){
        // cout<<n<<endl;
        if(n==0){
            dp[0]=0;
            return dp[0];
        }
        if(n==1){
            dp[1]=1;
            return dp[1];
        }
        if(dp[n]!=10000000){
            return dp[n];
        }

        int udx=upper_bound(sq.begin(),sq.end(),n)-sq.begin()-1;

        for(;udx>=0;udx--){
            dp[n]=min(dp[n],helper(n-sq[udx])+1);
        }
        
        return dp[n];
    }

    int numSquares(int n) {
        for(int i=0;i<10001;i++){
            dp[i]=10000000;
        }

        for(int i=1;i<=100;i++){
            sq.push_back(i*i);
        }

        helper(n);
        
        return dp[n];
    }
};