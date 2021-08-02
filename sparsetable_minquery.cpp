#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long

const int INF=1e7;

void solve(int arr[],int N){
    int st[N][N];

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            st[i][j]=INF;

    // base case st[a][b] b-a+1=1 b=a
    for(int a=0;a<N;a++)
        st[a][a]=arr[a];

    // recursive case st[a][b] b-a+1=jump
    for(int jump=2;jump-1<N;jump<<=1)
        for(int a=0;a+jump-1<N;a++)
            st[a][a+jump-1]=min(st[a][a+jump/2-1],st[a+jump/2][a+jump-1]);

    while(true){
        int l,r;
        scanf("%d %d",&l,&r);
        
        int p=1,gap=r-l+1;

        while(p<<1<gap)
            p<<=1;
        
        // min(st[l][r])=min(st[l][l+p-1],st[l+p][r])

        printf("%d\n",min(st[l][l+p-1],st[r-p+1][r]));
    }
}
   

int main(){
    int N;

    scanf("%d",&N);

    int arr[N];

    for(int i=0;i<N;i++)
        scanf("%d",arr+i);

    solve(arr,N);

    return 0;
}
