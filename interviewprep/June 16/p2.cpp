class Solution {
public:
    void split(string s, string del, vector<string>& chunks) {
        int st = 0, en = s.find(del);
        while(en!=-1) {
            chunks.push_back(s.substr(st, en - st));
            st = en + del.size();
            en = s.find(del, st);
        }
        
        chunks.push_back(s.substr(st, en - st));
    }
    int lengthLongestPath(string input) {
        vector<string>chunks;
        split(input, "\n", chunks);
        
        int ans = 0;
        unordered_map<int,int>paths;
        
        for(auto c: chunks) {
            int i = 0, path_len = 0;
            while(i<c.size() && c[i] == '\t') i++;
            
            if(i == 0) path_len = c.size();
            else path_len = paths[i-1] + 1 + (c.size() - i);
            
            if(count(c.begin(), c.end(), '.') != 0) ans = max(ans, path_len);
            else paths[i] = path_len;
        }
        
        return ans;
    }
};