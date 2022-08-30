class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<int> result;

        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        int p1=0, p2=0;
        
        while(p1<slots1.size() && p2<slots2.size()){
            int t11=slots1[p1][0], t12=slots1[p1][1], t21=slots2[p2][0], t22=slots2[p2][1];

            if(t11 > t22){
                p2++;
                continue;
            }

            if(t21 > t12){
                p1++;
                continue;
            }

            int c1=max(t11, t21), c2=min(t12, t22);
            if(c2-c1>=duration){
                result.push_back(c1);
                result.push_back(c1+duration);
                return result;
            }

            if(t12 < t22){
                p1++;
            }else{
                p2++;
            }
        }

        return result;
    }
};