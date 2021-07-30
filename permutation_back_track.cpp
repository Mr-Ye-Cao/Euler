#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long


void helper(vector<int> a,vector<int> b,vector<bool> chosen){
    if(b.size()==a.size()){
        for(int i=0;i<b.size();i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<chosen.size();i++){
        if(chosen[i]) continue;
        
        // choose
        chosen[i]=true;
        b.push_back(a[i]);

        // explore
        helper(a,b,chosen);

        // backtrack
        chosen[i]=false;
        b.pop_back();
    }
}


void perm(int n){
    vector<int> a(n);
    vector<bool> chosen(n,false);
    vector<int> permuta;

    for(int i=0;i<n;i++)
        a[i]=i;

    helper(a,permuta,chosen);
}

int main(){   
    int n;

    scanf("%d",&n);

    perm(n);

    return 0;
}
