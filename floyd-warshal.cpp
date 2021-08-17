#include <bits/stdc++.h>
using namespace std;

int N,M;
const int MAXN=1e3,INF=1e8;

void Query(int dis[MAXN][MAXN]){
    while(true){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",dis[a][b]);
    }
}

void solve(vector<int> nodes,int edges[MAXN][MAXN]){
    int dis[MAXN][MAXN];

    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            if(a==b){
                dis[a][b]=0;
                dis[b][a]=0;
            }else if(edges[a][b]!=INF){
                dis[a][b]=edges[a][b];
                dis[b][a]=edges[a][b];
            }else{
                dis[a][b]=INF;
                dis[b][a]=INF;
            }
        }
    }

    for(int k=0;k<N;k++){
        for(int a=0;a<N;a++){
            for(int b=0;b<N;b++){
                dis[a][b]=min(dis[a][b],dis[a][k]+edges[k][b]);
                dis[b][a]=min(dis[b][a],dis[b][k]+edges[k][a]);
            }
        }
    }

    Query(dis);
}

int main(){
    scanf("%d %d",&N,&M);

    vector<int> nodes(N);
    int edges[MAXN][MAXN];

    for(int i=0;i<N;i++)
        nodes[i]=i;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
                edges[i][j]=INF;
        
        
    for(int i=0;i<M;i++){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        edges[a][b]=w;
        edges[b][a]=w;
    }

    solve(nodes,edges);

    return 0;
}
