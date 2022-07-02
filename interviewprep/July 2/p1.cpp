class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        for(int i=0;i<s.length();i++){
            vector<int> v(2);
            v[0]=i;
            for(int j=i+1;j<s.length();j++){
                if(s[i]!=s[j]){
                    i=j-1;
                    v[1]=j-1;
                    break;
                }
                if(j==s.length()-1){
                    i=j;
                    v[1]=j;
                }
            }
            if(v[1]-v[0]+1>=3){
                result.push_back(v);
            }
        }

        return result;
    }
};