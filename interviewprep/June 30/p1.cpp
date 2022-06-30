class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size()!=sentence2.size()){
            return false;
        }

        map<string,set<string>> sm;

        for(int i=0;i<similarPairs.size();i++){
            if(sm.find(similarPairs[i][0])==sm.end()){
                set<string> ss;
                ss.insert(similarPairs[i][1]);
                sm[similarPairs[i][0]]=ss;
            }else{
                sm[similarPairs[i][0]].insert(similarPairs[i][1]);
            }

            if(sm.find(similarPairs[i][1])==sm.end()){
                set<string> ss;
                ss.insert(similarPairs[i][0]);
                sm[similarPairs[i][1]]=ss;
            }else{
                sm[similarPairs[i][1]].insert(similarPairs[i][0]);
            }
        }

        for(int i=0;i<sentence1.size();i++){
            if(sentence1[i]==sentence2[i]){
                continue;
            }

            if(sm.find(sentence1[i])==sm.end()&&sm.find(sentence2[i])==sm.end()){
                return false;
            }

            if(sm.find(sentence1[i])!=sm.end() && sm[sentence1[i]].find(sentence2[i])!=sm[sentence1[i]].end()){
                continue;
            }else if(sm.find(sentence2[i])!=sm.end() && sm[sentence2[i]].find(sentence1[i])!=sm[sentence2[i]].end()){
                continue;
            }else{
                return false;
            }
        }

        return true;
    }
};