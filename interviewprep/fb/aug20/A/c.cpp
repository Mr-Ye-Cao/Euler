class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums)
            sum+=num;
        
        if(sum%2==1)
            return false;
        
        int achi=sum/2;
        
        std::sort(nums.begin(),nums.end());
        
        if(nums[nums.size()-1]>achi)
            return false;
                
        vector<bool> dp(achi+1,false);
        dp[achi]=true;
        
        for(int i=0;i<nums.size();i++){
            // by simply changing the order of dp
            // from achi->0 to 0->achi will avoid the
            // double spending problem
            for(int j=0;j<=achi;j++){
                if(dp[j]&&j-nums[i]>=0){
                    dp[j-nums[i]]=true;
                }
            }
            if(dp[0])
                return true;
        }
        
        return dp[0];
    }
};