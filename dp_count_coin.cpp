#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long

const int MAXN=1e5,INF=1e6;
int x;
int dp[MAXN];
int fi[MAXN];
vector<int> c(3);

int solve(int x){
    // dp[0] = 1
    // dp[s+c] = min(dp[s+c], dp[s]+1) c={1,2,3}

    for(int s=0;s<=x;s++){
        for(int i=0;i<3;i++){
            if(dp[s+c[i]]>dp[s]+1){
                dp[s+c[i]]=dp[s]+1;
                fi[s+c[i]]=c[i];
            }
        }
    }

    return dp[x];
}


int main(){

    c[0]=1;c[1]=2;c[2]=3;

    scanf("%d",&x);
    memset(dp,INF,MAXN);
    dp[0]=0;
    
    int mn=solve(x);

    while(x>0){
        cout<<fi[x]<<" ";
        x-=fi[x];
    }

    return 0;
}
