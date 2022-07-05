class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        int is=0,it=0;
        unordered_map<char,int> ms,mt;
        vector<int> vs,vt;
        for(int i=0;i<s.length();i++){
            char cs=s[i],ct=t[i];
            if(ms.find(cs)==ms.end()){
                ms[cs]=is;
                is++;
            }
            if(mt.find(ct)==mt.end()){
                mt[ct]=it;
                it++;
            }

            vs.push_back(ms[cs]);
            vt.push_back(mt[ct]);
        }

        for(int i=0;i<vs.size();i++){
            if(vs[i]!=vt[i]){
                return false;
            }
        }

        return true;
    }
};