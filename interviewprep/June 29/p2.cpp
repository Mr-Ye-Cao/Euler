class Solution {
public:
    bool queryString(string s, int n) {
        // one digit: 1
        if(s.find("1")==string::npos){
            return false;
        }

        for(int num=1;num<=n;num++){
            int cnum=num;
            string s1="";
            while(cnum) {
                s1 += (cnum%2) + '0';
                cnum /= 2;
            }
            reverse(s1.begin(),s1.end()); 
            if(s.find(s1)==string::npos){
                return false;
            }
        }

        return true;
    }
};