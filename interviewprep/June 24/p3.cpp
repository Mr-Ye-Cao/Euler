class Solution {
public:
    int confusingNumberII(int n) {
        queue<int> numQueue;
        int res = 0;
        numQueue.push(0);
        unordered_map<int,int> m {{0,0},{1,1},{6,9},{8,8},{9,6}};
        while(!numQueue.empty())
        {
            auto tmpNum = numQueue.front();
            numQueue.pop();
            int rotated = 0;
            for(int k = tmpNum ; k > 0 ; k/= 10)
                rotated = rotated * 10 + m[k % 10];

            // res++ if rotated != tmpNum;
            res += rotated != tmpNum;
        
            for(auto record : m)
            {
                long next = tmpNum * 10L + record.first;
                if(next <= n && next != 0)
                    numQueue.push(next);
            }
        }
        
        return res;
    }
};