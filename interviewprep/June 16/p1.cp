class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        vector<char> sv;
        

        for(int i=0;i<s.length();i++){
            if(s[i]!='-'){
                if(isalpha(s[i])){
                    sv.push_back(toupper(s[i]));
                }else{
                    sv.push_back(s[i]);
                }
            }
        }
        
        // for(int i=0;i<sv.size();i++){
        //     cout<<sv[i]<<endl;
        // }

        string result="";

        for(int i=0;i<sv.size()%k;i++){
            result+=sv[i];
        }

        if(result!=""){
            result+="-";
        }

        for(int i=sv.size()%k;i<sv.size();i+=k){
            string w="";

            for(int j=i;j<i+k;j++){
                w+=sv[j];
            }
            result+=w + "-";
        }

        // string result="";

        // for(int i=0;i<sv.size()-(sv.size()%k);i+=k){
        //     string w="";

        //     for(int j=i;j<i+k;j++){
        //         w+=sv[j];
        //     }
        //     result+=w + "-";
        // }
    

        
        // result = result.substr(0, result.length()-1);
        // for(int i=sv.size()-(sv.size()%k);i<sv.size();i++){
        //     if(i==sv.size()-sv.size()%k){
        //         result="-"+result;
        //     }
        //     result=sv[i]+result;
        // }


        return result.substr(0,result.length()-1);
    }
};