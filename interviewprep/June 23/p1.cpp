class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int fp=arr.size()/20;
        double sum=0;
        for(int i=fp;i<arr.size()-fp;i++){
            sum+=arr[i];
        }

        return sum/(arr.size()-fp-fp);
    }
};