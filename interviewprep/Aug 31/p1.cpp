class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int points=0;
        int cc=0;

        for(int i=0;i<k;i++){
            cc+=calories[i];
        }

        if(cc<lower){
            points-=1;
        }else if(cc>upper){
            points+=1;
        }

        for(int i=k;i<calories.size();i++){
            cc=cc-calories[i-k]+calories[i];

            if(cc<lower){
                points-=1;
            }else if(cc>upper){
                points+=1;
            }
        }

        return points;
    }
};