class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> vd;
        set<int> sd;
        for(int i=0;i<time.length();i++){
            if(i!=2){
                cout<<(int)(time[i])-(int)'0'<<endl;
                vd.push_back((int)(time[i])-(int)'0');
                sd.insert((int)(time[i])-(int)'0');
            }
        }

        if(sd.size() == 1){
            return time;
        }

        string result="";
        int diff=INT_MAX;
        int maxtime=60*23+59;
        int t0=(vd[2]*10+vd[3])+(vd[0]*10+vd[1])*60;

        vector<int> vdc(4);
        for(auto& ht : sd){
            vdc[0]=ht;
            for (auto& ho : sd){
                vdc[1]=ho;
                for (auto& mt : sd){
                    vdc[2]=mt;
                    for (auto& mo : sd){
                        vdc[3]=mo;
                        int t1=(vdc[2]*10+vdc[3])+(vdc[0]*10+vdc[1])*60;
                        if(t1>maxtime || t1==t0 || (vdc[0]*10+vdc[1]) > 23 || 
                            (vdc[2]*10+vdc[3]) > 59){
                            continue;
                        }
                        if(t1<t0){
                            t1+=60*24;
                        }
                        if(t1-t0<diff){
                            diff=t1-t0;
                            result=to_string(ht) + to_string(ho) + ':' + to_string(mt) + to_string(mo);
                        }
                    }
                }
            }
        }

        return result;

    }
};