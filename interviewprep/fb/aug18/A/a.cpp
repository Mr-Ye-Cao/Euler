class Solution {
public:
    int daysBetweenDates(string dat1, string dat2) {        
        if(dat1>dat2){
            string tem=dat1;
            dat1=dat2;
            dat2=tem;
        }
        
        vector<int> month(12);
        month[0]=31;
        month[1]=29;
        month[2]=31;
        month[3]=30;
        month[4]=31;
        month[5]=30;
        month[6]=31;
        month[7]=31;
        month[8]=30;
        month[9]=31;
        month[10]=30;
        month[11]=31;
        
        int res=0;
        vector<int> date1(3);
        vector<int> date2(3);
        string y1,y2,m1,m2,d1,d2;
        
        y1=dat1.substr(0,dat1.find_first_of('-'));
        y2=dat2.substr(0,dat2.find_first_of('-'));
        
        m1=dat1.substr(dat1.find_first_of('-')+1,2);
        m2=dat2.substr(dat2.find_first_of('-')+1,2);
        
        d1=dat1.substr(dat1.find_last_of('-')+1);
        d2=dat2.substr(dat2.find_last_of('-')+1);
        
        if(m1[0]=='0'){
            m1=m1.substr(1);
        }
        if(m2[0]=='0'){
            m2=m2.substr(1);
        }
        if(d1[0]=='0'){
            d1=d1.substr(1);
        }
        if(d2[0]=='0'){
            d2=d2.substr(1);
        }
        
        date1[0]=std::stoi(y1);date1[1]=std::stoi(m1);date1[2]=std::stoi(d1);
        date2[0]=std::stoi(y2);date2[1]=std::stoi(m2);date2[2]=std::stoi(d2);
        
        if(date1[0]==date2[0]){
            // same year
            for(int i=0;i<date2[1]-1;i++){
                if(i==1){
                    if(date2[0]%4==0){
                        res+=29; 
                    }else{
                        res+=28;
                    }
                }else{
                    res+=month[i];
                }
            }
                res+=date2[2];
            
            for(int i=0;i<date1[1]-1;i++){
                if(i==1){
                    if(date1[0]%4==0){
                        res-=29; 
                    }else{
                        res-=28;
                    }
                }else{
                    res-=month[i];
                }
            }
            
                res-=date1[2];
            
            return res;
        }else{
            // cout<<dat1<<" "<<dat2;
            for(int i=date1[0];i<date2[0];i++){
                if(i%4==0){
                    res+=366;
                }else{
                    res+=365;
                }
            }
            for(int i=0;i<date2[1]-1;i++){
                if(i==1){
                    if(date2[0]%4==0&&(date2[0]%100!=0||date2[0]%400==0)){
                        res+=29; 
                    }else{
                        res+=28;
                    }
                }else{
                    res+=month[i];
                }
            }
                res+=date2[2];
            
            for(int i=0;i<date1[1]-1;i++){
                if(i==1){
                    if(date1[0]%4==0){
                        res-=29; 
                    }else{
                        res-=28;
                    }
                }else{
                    res-=month[i];
                }
            }
            
                res-=date1[2];
            return res;
        }

    }
};