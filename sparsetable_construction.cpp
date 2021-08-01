#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long

const int INF=1e9;

void solve(int arr[],int N){
    int st[N][N];

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            st[i][j]=INF;

    // st[a][b] b-a+1=2^i

    // base case b-a+1=1 i=0  b=a
    for(int a=0;a<N;a++)
        st[a][a]=arr[a];

    // recursive case b=a+2^i - 1
    for(int jump=2;jump-1<N;jump<<=1){
        for(int a=0;a+jump-1<N;a++){
            int b=a+jump-1;
            int w=(b-a+1)/2;
            st[a][b]=min(st[a][a+w-1],st[a+w][b]);
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(st[i][j]==INF)
                printf("_");
            else
                printf("%d",st[i][j]);
        }
            printf("\n");
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
