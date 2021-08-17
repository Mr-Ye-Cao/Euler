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

void solve(int N,int M,vector<int> nodes,vector<pair<int,int> > edges[]){
    vector<int> dis(N,INF);
    vector<bool> processed(N,false);
    priority_queue<pair<int,int> > pq; 

    dis[0]=0;
    pq.push({0,0});

    while(!pq.empty()){
        int a;
      
        a=pq.top().second;
        pq.pop();
        if(processed[a])
            continue;
        processed[a]=true;
        for(auto neighbor:edges[a]){
            int b=neighbor.first,w=neighbor.second;
            if(dis[a]+w<dis[b]){
                dis[b]=dis[a]+w;
                pq.push(make_pair(-dis[b],b));
            }
        }
    }

    Query(dis);
}

int main(){
    int N,M;

    scanf("%d %d",&N,&M);

    vector<int> nodes(N);
    vector<pair<int,int> > edges[M];

    for(int i=0;i<N;i++)
        nodes[i]=i;

    for(int i=0;i<M;i++){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        // Dijackstra's algorithm require non-negative edge
        edges[a].push_back(make_pair(b,w));
        edges[b].push_back(make_pair(a,w));
    }

    solve(N,M,nodes,edges);

    return 0;
}
