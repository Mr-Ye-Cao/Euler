class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            set<int> s;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(s.find(board[i][j])!=s.end()){
                        return false;
                    }else{
                        s.insert(board[i][j]);
                    }
                }
            }        
        }
        
        for(int i=0;i<9;i++){
            set<int> s;
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    if(s.find(board[j][i])!=s.end()){
                        return false;
                    }else{
                        s.insert(board[j][i]);
                    }
                }
            }        
        }
        
        vector<pair<int,int> > toche;
        toche.push_back({0,0});
        toche.push_back({0,3});
        toche.push_back({0,6});
        
        toche.push_back({3,0});
        toche.push_back({3,3});
        toche.push_back({3,6});
        
        toche.push_back({6,0});
        toche.push_back({6,3});
        toche.push_back({6,6});
        
        for(int i=0;i<toche.size();i++){
            set<int> s;
            for(int sx=toche[i].first;sx<toche[i].first+3;sx++){
                for(int sy=toche[i].second;sy<toche[i].second+3;sy++){
                    if(board[sx][sy]!='.'){
                        if(s.find(board[sx][sy])!=s.end()){
                            return false;
                        }else{
                            s.insert(board[sx][sy]);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};