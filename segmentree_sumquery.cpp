#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long

void solve(int arr[],int N){
    int tr[2*N];

    // base case: leaf node
    for(int i=0;i<N;i++)
        tr[i+N]=arr[i];

    // recursive case: parent node tr[p] = tr[c1]+tr[c2]
    for(int i=N-1;i>=0;i--)
        tr[i]=tr[i<<1]+tr[i<<1|1];
    
    while(true){
        int l,r;
        scanf("%d %d",&l,&r);

        int res=0;
        l+=N;r+=N;
        while(l<=r){
            // if left end is half of what completes
                // prune the left half and move upward the tree
            if(l%2==1) res+=tr[l++];
            // if right end is half of what completes
                // prune the right half and move upward the tree
            if(r%2==0) res+=tr[r--];
            l>>=1;r>>=1;
        }
        printf("%d\n",res);
    }

    for(int i=0;i<2*N;i++)
        printf("%d ",tr[i]);
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
