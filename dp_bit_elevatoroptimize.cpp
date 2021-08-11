#include <bits/stdc++.h>
using namespace std;

void solve(int arr[],int N,int W){
    pair<int,int> dp[1<<N];

    dp[0]={1,0};

    for(int i=1;i<(1<<N);i++){
        dp[i]={N+1,0};

        for(int j=0;j<N;j++){
            if(i&(1<<j)){
                // extract an option from dp that previously do not contain passenger i
                pair<int,int> option=dp[i^(1<<j)];
                
                if(option.second+arr[j]<=W){
                    option.second+=arr[j];
                }else{
                    option.first++;
                    option.second=arr[j];
                }

                dp[i]=min(dp[i],option);
            }
        }
    }

    printf("%d\n",dp[(1<<N)-1].first);
}

int main(){
    int N,W;

    scanf("%d %d",&N,&W);

    int arr[N];

    for(int i=0;i<N;i++)
        scanf("%d",arr+i);

    solve(arr,N,W);

    return 0;
}
