class Solution {
public:
    string getHint(string secret, string guess) {
        set<int> b;
        unordered_map<char,int> s;
        unordered_map<char,int> g;

        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                b.insert(i);
            }else{
                if(s.find(secret[i])==s.end()){
                    s[secret[i]]=1;
                }else{
                    s[secret[i]]++;
                }
                if(g.find(guess[i])==g.end()){
                    g[guess[i]]=1;
                }else{
                    g[guess[i]]++;
                }   
            }
        }

        int c=0;
        for(auto p:g){
            if(s.find(p.first)!=s.end()){
                c+=min(s[p.first],p.second);
            }
        }

        return to_string(b.size())+"A"+to_string(c)+"B";
    }
};