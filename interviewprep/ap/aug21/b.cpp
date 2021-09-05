class Solution {
public:
    int max(int a,int b){
        return a>b?a:b;
    }
    
    int min(int a,int b){
        return a>b?b:a;
    }
    
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        std::sort(slots1.begin(),slots1.end());
        std::sort(slots2.begin(),slots2.end());
        
        vector<int> res;
        int p1=0,p2=0;
        while(p1!=slots1.size()&&p2!=slots2.size()){
            cout<<p1<<" "<<p2<<"\n";

            if(slots1[p1][0]>=slots2[p2][1]){
                p2++;
                continue;
            }
            if(slots2[p2][0]>=slots1[p1][1]){
                p1++;
                continue;
            }
            
            if(min(slots1[p1][1],slots2[p2][1])-max(slots1[p1][0],slots2[p2][0])>=duration){
                res.push_back(max(slots1[p1][0],slots2[p2][0]));
                res.push_back(max(slots1[p1][0],slots2[p2][0])+duration);
                return res;
            }else{
                if(p1==slots1.size()-1){
                    p2++;
                    continue;
                }
                if(p2==slots2.size()-1){
                    p1++;
                    continue;
                }
                if(slots1[p1+1][0]>slots2[p2+1][0]){
                    p2++;
                }else{
                    p1++;
                }
            }
        }
        
        return res;
    }
};