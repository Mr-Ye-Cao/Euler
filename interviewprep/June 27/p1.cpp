class Solution {
public:
    bool isSubsequence(string s, string t) {
        map<char, vector<int>> chp;
        for(int i=0;i<t.length();i++){
            char c=t[i];
            if(chp.find(c)==chp.end()){
                vector<int> v;
                v.push_back(i);
                chp[c]=v;
            }else{
                chp[c].push_back(i);
            }
        }

        int pidx=-1;

        for(char c:s){
            if(chp.find(c)==chp.end()){
                return false;
            }else{
                vector<int> v=chp[c];
                int pos=upper_bound(v.begin(),v.end(),pidx)-v.begin();
                if(pos==v.end()-v.begin()){
                    return false;
                }
                
                pidx=v[pos];
            }
        }

        return true;
    }
};