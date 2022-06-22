class Solution {
public:
    bool checkRecord(string s) {
        int countA=0;

        for(int i=0;i<s.length();i++){
            if(s[i] == 'A'){
                countA++;
            }
        }

        if(countA >=2 ){
            return false;
        }


        for(int i=0;i<s.length();i++){
            if(s[i] == 'L'){
                int countL=1;
                for(int j=i+1;j<s.length();j++){
                    if(s[j]=='L'){
                        countL++;
                    }else{
                        break;
                    }
                }
                if(countL>=3){
                    return false;
                }
            }
        }

        return true;
    }
};