class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        unordered_map<long long,int> count;
        for(int i=0;i<nums.size();i++)
            count[nums[i]]++;
        
        int n=nums.size();
        if(count[target]>n/2)
            return true;
        else
            return false;
    }
};