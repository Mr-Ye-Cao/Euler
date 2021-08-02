#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long

const int INF=1e9;

void solve(int arr[],int N){
    int st[N][N];

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            st[i][j]=-INF;

    // base case st[a][b] b-a+1=1 b=a
    for(int a=0;a<N;a++)
        st[a][a]=arr[a];

    // recursive case st[a][b] b-a+1=jump b=a+jump-1
    for(int jump=2;jump-1<N;jump<<=1)
        for(int a=0;a+jump-1<N;a++)
            st[a][a+jump-1]=max(st[a][a+jump/2-1],st[a+jump/2][a+jump-1]);

    while(true){
        int l,r;
        scanf("%d %d",&l,&r);
        int ig=1,gap=r-l+1;
        while((1<<ig)<gap)
            ig<<=1;

        printf("%d\n",max(st[l][l+ig-1],st[r-ig+1][r]));
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
