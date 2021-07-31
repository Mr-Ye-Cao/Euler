#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long

const int INF=1e7;
void solve(string a,string b){
    if(a==""||b==""){
        printf("%d",max(a.length(),b.length()));
        return;
    }
    // dp[i][j]:= the distance from prefix a[0,i] to b[0,j]
    int dp[a.length()][b.length()];

    for(int i=0;i<a.length();i++)
        for(int j=0;j<b.length();j++)
            dp[i][j]=INF;

    // dp[0][0] = 0 ? 1 | a[0]!=b[0]   modify the char as there is no other faster way
    dp[0][0]=a[0]!=b[0]?1:0;

    for(int i=1;i<a.length();i++){
        for(int j=1;j<b.length();j++){
            if(a[i]==b[j])
                dp[i][j]=min(dp[i][j],min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1])));
            else
                dp[i][j]=min(dp[i][j],min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+1)));
        }
    }

    printf("%d",dp[a.length()-1][b.length()-1]);

}

int main(){
    string a,b;
    cin>>a>>b;
    solve(a,b);

    return 0;
}
