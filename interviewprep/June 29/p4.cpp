class Solution {
public:
    int dp[1001];

    int solve(vector<vector<int>>& books, int shelfWidth, int cur){
        if(cur < 0)
            return 0;
        
        if(dp[cur] != -1)
            return dp[cur];
        
        // we have to keep atleast one book at a level to count it in our answer
        // minLevelHeight - stores the minimum height at current Level to arrange the remaining books (cur-1 books) + cur'th book
        // curShelfWidth - width left at current level after placing one book 
        // mx_height stores max height among all books placed at current height
        
        int mx_height = books[cur][1], minLevelHeight = INT_MAX;
        int curShelfWidth = shelfWidth - books[cur][0];
        
        // base case: only one book
        //      place this book at cur level and return its height
        if(cur == 0)
            return mx_height;
        
        // recursive case:
        for(int i=cur-1; i>=0;i--){
            int curHeight = books[i][1], curWidth = books[i][0];
            
            int op1 = INT_MAX, op2 = INT_MAX;
            
            // there is enough space for this book on current level(curShelfWidth)
            // we have two options
            // 1) place this book at next level 
            // 2) place this book at current level and books after that in next level
            // take minimum of both answer for cur level 
            if(curWidth <= curShelfWidth){
                op1 = mx_height + solve(books, shelfWidth, i);  // take this book to next level
                
                mx_height = max(mx_height,curHeight);    // place this book at cur level, so take maximum of all books placed at this level
                op2 = mx_height + solve(books, shelfWidth,  i-1);  // place this book at cur level and books before that to next level
                curShelfWidth -= curWidth;  // reduce the curShelfWidth by width of this book 
                
                minLevelHeight = min(minLevelHeight,min(op1,op2));
            } else {
                // if current book width is greater than the space left 
                // we have only one option to place this book at next level
                op1 = mx_height + solve(books, shelfWidth, i);
                minLevelHeight = min(minLevelHeight,op2);
                break;
            }
        }
        
        return dp[cur] = minLevelHeight;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        
        int n = books.size();
        
        memset(dp,-1,sizeof(dp));
        
        return solve(books, shelfWidth, n-1);
    }
};