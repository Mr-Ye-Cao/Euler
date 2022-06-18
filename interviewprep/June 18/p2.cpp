class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int l=s.length();

        string hs="";
        for(int k=1;k<=l/2;k++){
            hs+=s[k-1];
            if(l%k!=0){
                continue;
            }
            bool iffound=true;
            for(int j=k;j<l;j++){
                if(hs[j%k]!=s[j]){
                    iffound=false;
                    break;
                }
            }
            if(iffound)
                return true;
        }

        return false;
    }
};