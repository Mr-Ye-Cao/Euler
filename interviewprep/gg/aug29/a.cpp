class Solution {
public:
    bool confusingNumber(int n) {
        map<int,int> m;
        m[0]=0;
        m[1]=1;
        m[6]=9;
        m[8]=8;
        m[9]=6;
        
        vector<int> v1,v2;
        while(n!=0){
            if(m.find(n%10)==m.end())
                return false;
            v1.push_back(n%10);
            n/=10;
        }
    
        for(int i=0;i<v1.size();i++)
            v2.push_back(m[v1[i]]);
        
        reverse(v2.begin(),v2.end());
        
        for(int i=0;i<v1.size();i++)
            if(v1[i]!=v2[i])
                return true;
        
        return false;
    }
};