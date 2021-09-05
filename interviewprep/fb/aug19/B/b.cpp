class Solution {
public:
    vector<int> tem;
    vector<vector<int> > res;
    
    void backtrack(int sta,int n){
        if(n==1&&tem.size()>1){
            res.push_back(tem);
            return;
        }
        
        // explore
        for(int i=sta;i<=n;i++){
            if(n%i==0){
                // choose
                tem.push_back(i);
                backtrack(i,n/i);
                
                // erase
                tem.pop_back();
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        backtrack(2,n);

        return res;
    }
};