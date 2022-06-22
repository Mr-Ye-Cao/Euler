class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int arr[n+1];
        for(int i=0;i<n+1;i++){
            arr[i]=0;
        }

        for(int i=0;i<n;i++){
            arr[nums[i]]=1;
        }

        vector<int> result;
        for(int i=1;i<n+1;i++){
            if(arr[i]==0){
                result.push_back(i);
            }
        }


        return result;
    }
};