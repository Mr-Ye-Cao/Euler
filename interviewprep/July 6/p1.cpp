class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;

            int lv,rv;
            if(m==0){
                lv=INT_MIN;
            }else{
                lv=arr[m-1];
            }

            if(m==n-1){
                rv=INT_MIN;
            }else{
                rv=arr[m+1];
            }
            
            if(arr[m]>lv&&arr[m]>rv){
                return m;
            }else if(arr[m]<lv){
                r=m-1;
            }else{
                l=m+1;
            }
        }

        return -1;
    }
};