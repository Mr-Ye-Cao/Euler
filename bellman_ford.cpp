#include <bits/stdc++.h>
using namespace std;

void solve(int N,vector<int>& nodes, vector<tuple<int,int,int> > edges,int E){
    // bellman-ford algorithm
    vector<int> dis(N,100000000);
    dis[0]=0;

    for(int i=0;i<nodes.size()-1;i++){
        for(auto ed:edges){
            int a,b,w;
            tie(a,b,w)=ed;
            dis[b]=min(dis[b],dis[a]+w);
        }
    }

//     while(true){
//         int k;
//         scanf("%d",&k);
//         cout<<dis[k]<<"\n";
//     }
}

int main(){
    int N,E;

    scanf("%d %d",&N,&E);

    vector<int> nodes(N);
    vector<tuple<int,int,int> > edges;

    for(int i=0;i<N;i++)
        nodes[i]=i;

    int e=E;
    while(E--){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        edges.push_back(make_tuple(a,b,w));
    }
    solve(N,nodes,edges,e);

    return 0;
}
