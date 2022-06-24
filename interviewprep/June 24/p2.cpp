class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int vector<int> dp1(n,0);
        int vector<int> dp1(n,1);

        for(int i=1;i<n;++i){
            dp1[i]=dp2[i]=INT_MAX;

            // in order without a swap
            if(nums1[i-1]<nums1[i] and nums2[i-1]<nums2[i]){
                // check the case: previous not swap, now not swap
                dp1[i]=dp1[i-1];

                // check the case: previous swap, now swap
                dp2[i]=dp2[i-1]+1;
            }

            // in order with a swap
            if(nums2[i-1]<nums1[i] and nums1[i-1]<nums2[i]){
                // check the case: previous swap now not swap
                dp1[i]=min(dp1[i],dp2[i-1]);

                // check the case: previous not swap now swap
                dp2[i]=min(dp2[i],dp1[i-1]+1);
            }
        }


        return min(dp1[n-1],dp2[n-1]);
    }
};