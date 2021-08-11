#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long

void solve(int arr[],int N){
    int bit[N+1];

    bit[0]=0;

    for(int i=1;i<N+1;i++)
        bit[i]=arr[i-1];
       

    for(int i=1;i<N+1;i++){
        int pi=(i+(i&-i));
        while(pi<N+1){
            bit[pi]+=arr[i-1];
            pi+=(pi&-pi);
        }
    }

    for(int i=0;i<N+1;i++)
        printf("%d ",bit[i]);

    while(true){
        int l,r;
        scanf("%d %d",&l,&r);

        l--;
        int lr=0,rr=0;
        while(l>=1){
            lr+=bit[l];
            l-=l&-l;
        }
        while(r>=1){
            rr+=bit[r];
            r-=r&-r;
        }

        printf("%d\n",rr-lr);

        // sum(l,r)=sum(1,r)-sum(1,l-1)
    }

}

int main(){
    int N;

    scanf("%d",&N);

    int arr[N];

    for(int i=0;i<N;i++)    
        scanf("%d",arr+i);

    solve(arr,N);

//     while(true){
//         int n;
//         scanf("%d",&n);
//         printf("%d",(n-(n&-n)));
//     }
    // 7->6->4->0   for computing sum(1,k) it is broken into several pieces and sum every piece together

    return 0;
}
