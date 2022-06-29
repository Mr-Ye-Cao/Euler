class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n=values.size();
        vector<pair<int,int> > vlp(n);
        
        for(int i=0;i<n;i++){
            vlp[i]=make_pair(values[i],labels[i]);
        }

        sort(vlp.begin(),vlp.end());
        reverse(vlp.begin(),vlp.end());
        
        vector<int> choose;
        map<int,int> lc;

        for(int i=0;i<vlp.size();i++){
            if(choose.size()==numWanted){
                break;
            }
            if(lc.find(vlp[i].second)==lc.end()){
                // label not yet used
                choose.push_back(vlp[i].first);
                lc[vlp[i].second]=1;
            }else if(lc[vlp[i].second]<useLimit){
                choose.push_back(vlp[i].first);
                lc[vlp[i].second]++;
            }else if(lc[vlp[i].second]==useLimit){
            }
        }

        int result=0;
        for(int i=0;i<choose.size();i++)
            result+=choose[i];

        return result;
    }
};