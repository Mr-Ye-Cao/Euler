class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=p.length();
        vector<int> res;
        unordered_map<char,int> comp;
        unordered_map<char,int> want;
        unordered_map<char,int> nwant;
        
        if(s.length()<p.length())
            return res;
                
        for(char c:p)
            comp[c]++;
        
        for(int i=0;i<n;i++){
            if(comp.find(s[i])==comp.end()){
                // not in component
                nwant[s[i]]++;
            }else{
                if(comp[s[i]]>0){
                    comp[s[i]]--;
                }else{
                    nwant[s[i]]++;
                }
            }        
        }
        
        for(auto it=comp.begin();it!=comp.end();it++){
            if((*it).second!=0){
                want[(*it).first]+=(*it).second;
            }
        }
        
        if(want.empty()&&nwant.empty()){
            res.push_back(0);
        }
        
        
        for(int i=n;i<s.length();i++){
            if(comp.find(s[i-n])!=comp.end()){
                if(nwant.find(s[i-n])!=nwant.end()){
                    nwant[s[i-n]]--;
                }else{
                    want[s[i-n]]++;
                }
            }else{
                nwant[s[i-n]]--;
            }
            
            if(nwant[s[i-n]]==0)
                    nwant.erase(s[i-n]);
            
            if(want.find(s[i])!=want.end()){
                // want it
                want[s[i]]--;
                if(want[s[i]]==0)
                    want.erase(s[i]);
            }else{
                // not want it
                nwant[s[i]]++;
            }
        
        
            if(nwant.empty()&&want.empty())
                res.push_back(i-n+1);
        }
        
        return res;
    }
};
