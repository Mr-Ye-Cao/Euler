#include <bits/stdc++.h>
using namespace std;

int solve(string s){
    int n=s.length();

    int arr[n][n];
    string rec[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=0;


    for(int i=0;i<n;i++){
        arr[i][i]=1;
        rec[i][i]=s[i];
    }

    for(int i=0;i<n-1;i++)
        if(s[i]==s[i+1]){
            arr[i][i+1]=2;
            rec[i][i+1]=s[i]+rec[i][i];
        }
        else{
            arr[i][i+1]=arr[i][i];
            rec[i][i+1]=rec[i][i];
        }

    for(int g=2;g<n;g++){
        for(int i=0;i+g<n;i++){
            int j=i+g;
            if(s[j]==s[i]){
                arr[i][j]=2+arr[i+1][j-1];
                rec[i][j]=s[i]+rec[i+1][j-1]+s[j];
            }
            else{
                arr[i][j]=max(arr[i+1][j],arr[i][j-1]);
                if(arr[i+1][j]>arr[i][j-1])
                    rec[i][j]=rec[i+1][j];
                else
                    rec[i][j]=rec[i][j-1];
            }
        }
    }

    cout<<rec[0][n-1]<<"\n";
    return arr[0][n-1];
}

int main(){
    string s;
    cin>>s;

    cout<<solve(s);

    return 0;
}
