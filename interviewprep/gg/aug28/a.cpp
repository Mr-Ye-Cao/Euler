class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int,int> > n1;
        vector<pair<int,int> > n2;
    
        for(int i=0;i<nums1.size();i++)
            n1.push_back(make_pair(nums1[i],i));
        
        for(int i=0;i<nums2.size();i++)
            n2.push_back(make_pair(nums2[i],i));
        
        std::sort(n1.begin(),n1.end());
        std::sort(n2.begin(),n2.end());
        
        vector<int> res(nums1.size());
        
        for(int i=0;i<n1.size();i++)
            res[n1[i].second]=n2[i].second;
        
        return res;
    }
};