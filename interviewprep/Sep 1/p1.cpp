class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";

        for(int i=0;i<s.length();i++){
            int l=i-1, r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                    l--;
                    r++;
            }
            l++;
            r--;
            if(l>=0 && r<s.length() && s[l]==s[r]){
                if(s.substr(l,r-l+1).length() > result.length()){
                    result=s.substr(l,r-l+1);
                }
            }
        }

        for(int i=0;i<s.length();i++){
            int l=i, r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                    l--;
                    r++;
            }
            l++;
            r--;
            if(l>=0 && r<s.length() && s[l]==s[r]){
                if(s.substr(l,r-l+1).length() > result.length()){
                    result=s.substr(l,r-l+1);
                }
            }
        }

        return result;
    }
};