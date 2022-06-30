class Solution {
public:
    unordered_map<string,string> parent;
    unordered_map<string,int> rank;

    string find(string s){
        if(parent[s]!=s){
            parent[s]=find(parent[s]);
        }

        return parent[s];
    }

    void unionops(string s1,string s2){
        string s1rep=find(s1);
        string s2rep=find(s2);
        if (s1rep == s2rep)
            return;
        if (rank[s1rep] < rank[s2rep]) {
            parent[s1rep] = s2rep;
        }
        else if (rank[s1rep] > rank[s2rep]) {
            parent[s2rep] = s1rep;
        }else {
            parent[s2rep] = s1rep;
            rank[s1rep] = rank[s1rep] + 1;
        }
    }

    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size()!=sentence2.size()){
            return false;
        }

        for(string s1:sentence1){
            parent[s1]=s1;
        }

        for(string s2:sentence2){
            parent[s2]=s2;
        }

        for(auto v:similarPairs){
            string w1=v[0],w2=v[1];
            unionops(w1,w2);
        }

        for(int i=0;i<sentence1.size();i++){
            string w1=sentence1[i],w2=sentence2[i];
            if(find(w1)!=find(w2)){
                return false;
            }
        }

        return true;
    }
};