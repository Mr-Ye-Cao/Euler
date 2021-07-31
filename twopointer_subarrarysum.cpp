#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long

/**
 * Two pointer method O(N)
 * subarrary sum
 * */

pair<int,int> solve(int arr[],int N,int S){

    // [p1,p2)
    int p1=0,p2=0,sum=0;

    while(p1<N&&p2<N){
        if(sum==S){
            return make_pair(p1,p2);
        }

        else if(sum<S){
            // move right pointer
            p2++;
            sum+=arr[p2-1];
        }

        else{
            // move left pointer
            p1++;
            sum-=arr[p1-1];
        }
    }

    return make_pair(-1,-1);
}


int main(){

    int N,S;

    scanf("%d %d",&N,&S);

    int arr[N];

    for(int i=0;i<N;i++)
        scanf("%d",arr+i);

    pair<int,int> res = solve(arr,N,S);

    cout<<res.first<<" "<<res.second<<"\n";

    return 0;
}
