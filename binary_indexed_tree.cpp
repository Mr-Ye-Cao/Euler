#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long

void solve(int arr[],int N){
    int bit[N+1];

    for(int i=0;i<N+1;i++)
        if(i==0)
            bit[i]=0;
        else
            bit[i+1]=arr[i];

    for(int i=1;i<N+1;i++){
        int pi=(i+(i&-i));
        while((i+i&-i)<N+1){
            bit[pi]+=arr[i-1];
            pi=(pi+(pi&-pi));
        }
    }
}

int main(){
    int N;

    scanf("%d",&N);

    int arr[N];

    for(int i=0;i<N;i++)    
        scanf("%d",arr+i);

    solve(arr,N);

    // printf("%d\n",1+(1&-1));

    return 0;
}
