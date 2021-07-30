#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int s,int mid,int e){
    vector<int> temp(e-s+1);

    bool ip1;
    int p1=s,p2=mid+1;  

    for(int i=0;i<temp.size();i++){
        /**
         * so if either p1 or p2 exhausts switch to another
         * otherwise compare them
         **/
        if(p1==mid+1){
            temp[i]=arr[p2];
            p2++;
        }else if(p2==e+1){
            temp[i]=arr[p1];
            p1++;
        }else{
            if(arr[p1]<arr[p2]){
                temp[i]=arr[p1];
                p1++;
            }else{
                temp[i]=arr[p2];
                p2++;
            }
        }
    }

    for(int i=0;i<temp.size();i++)
        arr[i+s]=temp[i];
}

void mergesort(int arr[],int s,int e){
    if(s<e){
        int mid=s+(e-s)/2;
        mergesort(arr,s,mid);
        mergesort(arr,mid+1,e);
        merge(arr,s,mid,e);
    }
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];
    
    for(int i=0;i<n;i++)
        scanf("%d",arr+i);

    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i));

    return 0;
}
