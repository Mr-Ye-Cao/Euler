class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        int dp[n][2];

        for(int i=0;i<n;i++){
            // initially all set to failure
            dp[i][0]=dp[i][1]=0;
        }

        // base case: last step is reachable from even or odd
        dp[n-1][0] = dp[n-1][1] = 1;

        // recursive case: non-last step
        for(int i=n-2;i>=0;i--){
            int vi=arr[i];

            // index it can reach with odd jump
                // the first index(>i) with smallest val no less than vi
            int oi=(lower_bound(arr.begin()+i+1,arr.end(),vi)-arr.begin());
            // index it can reach with even jump
                // the first index(>i) with largest val smaller than vi
            int ei=(upper_bound(arr.begin()+i+1,arr.end(),vi)-arr.begin());
                
            cout<<vi<<" "<<oi<<" "<<ei-1<<endl;;

            if(oi>=arr.size()){
                // cannot make any more move
                dp[i][0] = 0;
            }else{
                // even move starts here
                dp[i][0] = dp[oi][1];
            }

            if(ei>=arr.size() || ei-1 <= i){
                // cannot make any more move
                dp[i][1] = 0;
            }else{
                // odd move starts here
                dp[i][1] = dp[ei-1][0];
            }
        }

        int result=0;
        for(int i=0;i<n;i++){
            // cout<<dp[i][0]<<endl;
            // start every move with odd
            result+=dp[i][0];
        }

        return result;
    }
};

class Solution {
public:
    int oddEvenJumps(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int n = nums.size();
        map<int,int> mp;
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n-1][0] = dp[n-1][1] = 1;
        mp[nums[n-1]] = n-1;
        for(int i = n-2; i>=0;--i){
            auto it = mp.lower_bound(nums[i]);  auto it2 = it;
            if(it==mp.end()) it--;
            if(it->first>nums[i]){ 
                if(it!=mp.begin()){
                   it--; dp[i][0] = dp[it->second][1]; // even --> next( Odd ) jump
                }
            }
            else dp[i][0] = dp[it->second][1];
            if(it2!=mp.end()) dp[i][1] = dp[it2->second][0]; // odd  --> next( even ) jump
            mp[nums[i]] = i;
        }
        int re = 0;
        for(int i = 0; i<dp.size();++i) if(dp[i][1]==1) re++;
        return re;
    }
};