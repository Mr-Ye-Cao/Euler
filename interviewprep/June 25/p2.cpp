class Solution {
public:
    vector<string> option_helper(vector<string> pre,string options){
        vector<string> result;
        for(int i=0;i<pre.size();i++){
            for(int j=0;j<options.length();j++){
                if(options[j]==','){
                    continue;
                }else{
                    result.push_back(pre[i]+options[j]);
                }
            }
        }

        return result;
    }

    vector<string> expand(string s) {
        vector<string> result;
        result.push_back("");
        
        while(s!=""){
            cout<<s<<endl;
            // permutate process one letter
            if(s[0]=='{'){
                // option letter
                            cout<<"sub:"<<s.substr(1,s.find("}")-1)<<endl;
                result=option_helper(result,s.substr(1,s.find("}")-1));
                s=s.substr(s.find("}")+1);
            }else{
                // single letter
                for(int i=0;i<result.size();i++){
                    result[i]+=s[0];
                }
                s=s.substr(1);
            }
        }
        
        sort(result.begin(),result.end());
        return result;
    }
};