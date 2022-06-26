class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;

        vector<vector<int>> v(strings.size());

        for(int i=0;i<strings.size();i++){
            vector<int> vec(strings[i].length(),0);
            vec[0]=0;
            int df=(int)strings[i][0]-'a';
            for(int j=1;j<strings[i].length();j++){
                vec[j]=(((int)strings[i][j]-'a')-df)%26;
            }
            v[i]=vec;
        }

        vector<bool> checked(strings.size(),false);
        for(int i=0;i<v.size();i++){
            if(checked[i]){
                continue;
            }
            vector<string> presult;
            presult.push_back(strings[i]);
            vector<int> v1=v[i];
            for(int j=i+1;j<v.size();j++){
                if(checked[j]){
                    continue;
                }
                vector<int> v2=v[j];
                if(v1.size()==v2.size()){
                    bool same=true;
                    for(int k=0;k<v1.size();k++){
                        if(v1[k]<0){
                            v1[k]+=26;
                        }
                        if(v2[k]<0){
                            v2[k]+=26;
                        }
                        if(v1[k]!=v2[k]){
                            same=false;
                            break;
                        }
                    }
                    if(same){
                        presult.push_back(strings[j]);
                        checked[j]=true;
                    }
                }
            }

            result.push_back(presult);
        }


        return result;
    }
};