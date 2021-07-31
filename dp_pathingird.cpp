#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long

const int MAXN=1e6;
int dp[MAXN][MAXN];

void solve(vector<vector<int> > v){
    // dp[0][0] = v[0][0]
    dp[0][0]=v[0][0];

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            if(i+1<v.size()){
                // move down
                // dp[i+1][j] = max(dp[i+1][j],dp[i][j]+v[i+1][j])
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]+v[i+1][j]);
            }
            if(j+1<v[0].size()){
                // move right
                // dp[i][j+1] = max(dp[i][j+1],dp[i][j]+v[i][j+1])
                dp[i][j+1]=max(dp[i][j+1],dp[i][j]+v[i][j+1]);
            }
        }
    }

    printf("%d",dp[v.size()-1][v[0].size()-1]);
}


int main(){
    
    int M,N;
    scanf("%d %d",&M,&N);

    vector<vector<int> > v(M);

    for(int i=0;i<M;i++){
        v[i].resize(N);
        for(int j=0;j<N;j++){
            scanf("%d",&v[i][j]);
        }
    }

    solve(v);

    return 0;
}
