class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        vector<pair<int,int> > hour;
        vector<pair<int,int> > minute;

        // four choose 2
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                hour.push_back(make_pair(arr[i], arr[j]));
                vector<int> p;
                for(int k=0;k<arr.size();k++){
                    if(k!=i&&k!=j){
                        p.push_back(arr[k]);
                    }
                }
                minute.push_back(make_pair(p[0],p[1]));
            }
        }

        string result="";
        int latestTime=-1;

        // check each pair
        for(int i=0;i<hour.size();i++){
            // hour
            int h;
            int hp1=hour[i].first*10+hour[i].second,hp2=hour[i].second*10+hour[i].first;
            if(hp1 >= 24 && hp2 >= 24){
                continue;
            }
            if(max(hp1,hp2) < 24){
                h=max(hp1,hp2);
            }else{
                h=min(hp1,hp2);
            }
            // minute
            int m;
            int mp1=minute[i].first*10+minute[i].second,mp2=minute[i].second*10+minute[i].first;
            if(mp1 >= 60 && mp2 >= 60){
                continue;
            }
            if(max(mp1,mp2) < 60){
                m=max(mp1,mp2);
            }else{
                m=min(mp1,mp2);
            }
            // time
            if(latestTime < h*60+m){
                latestTime=h*60+m;
                result=(h/10==0 ? "0" + to_string(h) : to_string(h))+":"+
                        (m/10==0 ? "0" + to_string(m) : to_string(m));
            }
        }

        return result;
    }
};