class Solution {
public:
    vector<int> minOperations(string boxes) {
        // graph problem
        int n=boxes.length();
        vector<int> v(n,0);    
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(j==i)
                    continue;
                else{
                    if(boxes[j]=='1'){
                        if(j<i)
                            v[i]+=i-j;
                        else
                            v[i]+=j-i;
                    }
                }
        
        return v;
    }
};