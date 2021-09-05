class Solution {
public:
    int minAddToMakeValid(string s) {
        // #('C') = #(')')
        if(s=="")
            return 0;
        
        int p=0,cp1=0,res=0;
        
        while(p<s.length()){
            if(s[p]==')'){
                if(cp1==0)
                    res++;
                else
                    cp1--;
            }else{
                cp1++;
            }
            p++;
        }
        
        return res+cp1;
    }
};