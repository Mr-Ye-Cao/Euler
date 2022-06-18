class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }

        if(nums[0] > nums[1]){
            return 0;
        }

        if(nums[nums.size()-1] > nums[nums.size()-2]){
            return nums.size()-1;
        }

        int ldx=-1,rdx=nums.size();

        while(ldx<=rdx){
            int midx=(ldx+rdx)/2;
            int mval=nums[midx];

            int lval,rval;
            if(midx+1==nums.size()){
                rval=INT_MIN;
            }else{
                rval=nums[midx+1];
            }

            if(midx-1==-1){
                lval=INT_MIN;
            }else{
                lval=nums[midx-1];
            }

            if(mval > rval && mval > lval){
                return midx;
            }else if(mval < lval){
                // if go up left
                rdx=midx-1;
            }else{
                // if go up right
                ldx=midx+1;
            }
        }

        return -1;
    }
};