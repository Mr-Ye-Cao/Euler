class Solution {
public:
    string reorderSpaces(string text) {

        vector<string> words;
        int countSpace=0;
        string word="";

        for(int i=0;i<text.length();i++){
            if(text[i]==' '){
                countSpace++;
                if(word!=""){
                    words.push_back(word);
                    word="";
                }
            }else{
                word+=text[i];
            }
        }

        if(word!=""){
            words.push_back(word);
        }

        int n=words.size();
        string result="";
        if(n==1){
            result=words[0];
            for(int j=0;j<countSpace;j++){
                result+=" ";
            }
            return result;
        }
        int space=countSpace/(n-1);
        int extraspace=countSpace%(n-1);

        

        for(int i=0;i<n;i++){
            result+=words[i];
            if(i!=n-1){
                for(int j=0;j<space;j++){
                    result+=" ";
                }
            }
        }

        for(int j=0;j<extraspace;j++){
            result+=" ";
        }
        
        return result;
    }
};