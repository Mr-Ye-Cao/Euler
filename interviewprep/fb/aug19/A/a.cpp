class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int e=nums.size();
        
        for(int i=0;i<e;i++){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                i--;
                e--;
                nums.push_back(0);
            }
        }
        
    }
};