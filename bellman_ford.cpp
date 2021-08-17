#include <bits/stdc++.h>
using namespace std;
const int INF=1e8;

void Query(vector<int> dis){
    while(true){
        int destination;
        scanf("%d",&destination);
        cout<<dis[destination]<<"\n";
    }
}

void solve(int N,int M,vector<int> nodes,vector<tuple<int,int,int> > edges){
    // bellman-ford algorithm O(MN)
    vector<int> dis(N,INF);
    dis[0]=0;

    for(int i=0;i<N-1;i++){
        for(auto e:edges){
            int a,b,w;
            tie(a,b,w)=e;
            dis[b]=min(dis[b],dis[a]+w);
        }
    }

    Query(dis);
}

int main(){
    // Dijackstra's algorithm O(N+Mlog(M))

    int N,M;
    scanf("%d %d",&N,&M);

    vector<int> nodes(N);
    vector<tuple<int,int,int> > edges(2*M);

    for(int i=0;i<N;i++)
        nodes[i]=i;

    for(int i=0;i<2*M;i+=2){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        edges[i]=make_tuple(a,b,w);
        //for undirected graph add both direction
        edges[i+1]=make_tuple(b,a,w);
    }

    solve(N,M,nodes,edges);

    return 0;
}
