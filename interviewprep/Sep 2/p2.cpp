class Solution {
public:
    int r[4] = {-1,1,0,0};
    int c[4] = {0,0,-1,1};
    bool static cmp(array<int,3> &a,array<int,3>&b) {
         return a[0] < b[0];
    }
    int cutOffTree(vector<vector<int>>& forest) {
         int ans = 0;
         if(forest[0][0]==0) return -1;
         int n = forest.size() , m = forest[0].size();
         vector<array<int,3>> trees;
         for(int i=0; i<n; i++) {
             for(int j=0; j<m; j++) {
                  if(forest[i][j]>1) trees.push_back({forest[i][j],i,j});
             }
         }
         sort(trees.begin(),trees.end(),cmp);  // cut trees of next greater height than previous height!
         // can you reach the next greater tree ? or it is blocked by 0s? if it is then its not possible to cut otherwise answer always exists!
         int curR = 0 , curC = 0;
         for(array<int,3> nxt : trees) {
               int Rn = nxt[1] , Cn = nxt[2];
               if(forest[curR][curC] == forest[Rn][Cn]) {
                   curR = Rn;
                   curC = Cn;
                   continue;
               }
               queue<pair<int,int>> q;
               q.push({curR,curC});
               vector<vector<int>> vis(n,vector<int>(m,0));
               vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
               vis[curR][curC] = 1;
               dist[curR][curC] = 0;
               bool found = false;
               while(!q.empty()) {
                    pair<int,int> p = q.front();
                    q.pop();
                    for(int d = 0; d < 4; d++) {
                         int R = r[d] + p.first , C = c[d] + p.second;
                         if(R>=0 && R<n && C>=0 && C<m && !vis[R][C] && dist[R][C] > 1 + dist[p.first][p.second] && forest[R][C]) {
                              vis[R][C] = 1;
                              dist[R][C] = 1 + dist[p.first][p.second];
                              q.push({R,C});
                         }
                         if(R == Rn && C==Cn) {
                              ans+=dist[p.first][p.second];
                              ans++;
                              found = true;
                              break;
                         }
                    }
                   if(found) break;
               }
             if(!found) return -1;
             curR = Rn;
             curC = Cn;
         }
        return ans;
    }
};