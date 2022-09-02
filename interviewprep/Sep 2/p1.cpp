class Solution {
public:
    vector<string> split(string paragraph, string delim){
        vector<string> tokens;

        string token = "";
        
        for(int i=0;i<paragraph.length();i++){
            if((paragraph[i] >= 'a' && paragraph[i] <= 'z')||
                    (paragraph[i] >= 'A' && paragraph[i] <= 'Z')){
                token+=paragraph[i];
            }else{
                if(token != ""){
                    tokens.push_back(token);
                    token = "";
                }
            }
        }

        if(token != ""){
            tokens.push_back(token);
        }

        return tokens;
    }

    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> tokens = split(paragraph, " ");
        for(string token: tokens){
            cout<<token<<endl;
        }
        map<string, int> count;

        for(int i=0;i<tokens.size();i++){
            string token = "";
            for(int j=0;j<tokens[i].length();j++){
                if((tokens[i][j] >= 'a' && tokens[i][j] <= 'z')||
                    (tokens[i][j] >= 'A' && tokens[i][j] <= 'Z')){

                    if(tokens[i][j] >= 'A' && tokens[i][j] <= 'Z'){
                        token+=tolower(tokens[i][j]);
                    }else{
                        token+=tokens[i][j];
                    }
                }
            }

            tokens[i] = token;
        }


        for(string token: tokens){
            if(count.find(token) == count.end()){
                count[token] = 1;
            }else{
                count[token]++;
            }
        }

        set<string> banset;
        for(string bantoken: banned){
            banset.insert(bantoken);
        }


        string result = "";
        int resultcount = 0;

        for(map<string, int>::iterator it = count.begin(); it != count.end(); it++){
            if(it->second > resultcount && banset.find(it->first) == banset.end()){
                result = it->first;
                resultcount = it->second;
            }
        }

        return result;
    }
};