class Solution {
public:
    int calculateTime(string keyboard, string word) {
        map<char,int> k;
        for(int i=0;i<keyboard.length();i++){
            k[keyboard[i]]=i;
        }
        int pp=0;
        int result=0;
        for(char c:word){
            result+=abs(k[c]-pp);
            pp=k[c];
        }

        return result;
    }
};