class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0,cursum=0;
        unordered_map<int,int> um;
        
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            if(cursum==k)
                count++;
            if(um.find(cursum-k)!=um.end())
                count+=um[cursum-k];
            
            um[cursum]++;
        }
        
        return count;
    }
};