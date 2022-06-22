class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1){
            return true;
        }
        if(n<=0){
            return false;
        }

        vector<int> b(4);
        b[0] = 2;
        b[1] = 2*2;
        b[2] = 2*2*2;
        b[3] = 2*2*2*2;

        int t=3;
        while(n!=1 && t!=-1){
            if(n%b[t]==0){
                n/=b[t];
            }else{
                t--;
            }
        }

        if(n==1){
            return true;
        }else{
            return false;
        }
    }
};