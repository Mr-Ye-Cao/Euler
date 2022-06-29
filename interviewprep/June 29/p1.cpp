class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> result;

        vector<string> vs;
        
        while(text!=""){
            string word=text.substr(0,text.find(" "));
            if(text.find(" ")==string::npos){
                vs.push_back(text);
                break;
            }else{
                vs.push_back(word);
                text=text.substr(text.find(" ")+1);
            }
        }

        for(int i=0;i<vs.size()-2;i++){
            if(vs[i]==first && vs[i+1]==second){
                result.push_back(vs[i+2]);
            }
        }

        return result;
    }
};