class Solution {
public:
    int shortestWay(string source, string target) {
        map<char,vector<int> > appear;
        
        for(int i=0;i<source.length();i++)
            appear[source[i]].push_back(i);
        
        int res=0;
        while(target!=""){
            res++;
            
            if(appear[target[0]].empty())
                return -1;
            
            int idx=appear[target[0]][0];
            
            if(target.length()==1)
                return res;
            
            int i;
            for(i=1;i<target.length();i++){
vector<int>::iterator it=upper_bound(appear[target[i]].begin(),appear[target[i]].end(),idx);
                if(it==appear[target[i]].end()){
                    break;
                }else{
                    idx=*it;
                }
            }
            
            target.erase(0,i);
        }
                
        return res;
        
    }
};