class Solution {
public:
    
    bool simi(string a,string b){
        int diff=0;
        for(int i=0;i<a.length();i++)
            if(a[i]!=b[i] && ++diff>2)
                return false;
        
        return true;
    }
    
    int find_par(int par[],int chi){
        return par[chi] == chi ? chi : find_par(par,par[chi]);
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        int par[n];
        
        for(int i=0;i<strs.size();i++)
            par[i]=i;
        
        int res=n;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(simi(strs[i],strs[j])){
                    int p1=find_par(par,i);
                    int p2=find_par(par,j);
                    
                    if(p1!=p2){
                        par[p1]=p2;
                        res--;
                    }
                }
            }
        }
        
        return res;
    }
};