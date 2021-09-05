class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> um1;
        unordered_map<int,int> um2;
        
        for(int num:arr)
            um1[num]++;
        
        for(auto it=um1.begin();it!=um1.end();it++)
            um2[(*it).second]++;
        
        for(auto it=um2.begin();it!=um2.end();it++)
            if((*it).second>1)
                return false;
    
        return true;
    }
};