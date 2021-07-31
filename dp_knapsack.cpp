#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long

void solve(int sack[],int N){
    int mw=accumulate(sack,sack+N,0);
    
    // dp[i][w] using the first i objects in sack can acheive weight w    
    int dp[N+1][mw+1];

    for(int i=0;i<N+1;i++)
        for(int j=0;j<mw+1;j++)
            dp[i][j]=0;


    // dp[0][0] = 0 using 0 object can acheive weight 0
    dp[0][0] = 1;

    for(int i=1;i<=N;i++){
        dp[i][sack[i-1]]=1;
        for(int j=1;j<i;j++){
            for(int k=0;k<=mw;k++){
                // dp[j][w] include all dp[i][w]
                // dp[i][k]=max(dp[i][k],dp[j][k]);

                if(dp[j][k]==1){
                    // dp[j][w] include all dp[i][w]
                    dp[i][k]=1;
                    // dp[i][w+sack[i]]=1 | dp[j][w]=1 // i sack is open to use
                    dp[i][k+sack[i-1]]=1;
                }
            }
        }
    }

    for(int i=0;i<=mw;i++)
        if(dp[N][i]==1)
            printf("%d ",i);
}


int main(){
    
    int N;
    scanf("%d",&N);    

    int sack[N];

    for(int i=0;i<N;i++)
        scanf("%d",sack+i);

    solve(sack,N);

    return 0;
}
