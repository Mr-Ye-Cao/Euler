class Solution {
public:
    bool checksatis(string time,int h,int m){
        string hs=to_string(h);
        string ms=to_string(m);
        if((hs.length()==1||ms.length()==1)&&time.find("0")==string::npos)
            return false;
        
        for(char c:hs)
            if(time.find(c)==string::npos)
                return false;
        for(char c:ms)
            if(time.find(c)==string::npos)
                return false;
        
        return true;
    }
    
    string process(int h,int m){
        string hs=to_string(h);
        string ms=to_string(m);
        
        if(hs.length()==1)
            hs="0"+hs;
        if(ms.length()==1)
            ms="0"+ms;
        
        return hs+":"+ms;
    }
    
    string nextClosestTime(string time) {
        string res;
        string hour=time.substr(0,2);
        string mint=time.substr(3);
        
        if(hour[0]=='0')
            hour=hour.substr(1);
        if(mint[0]=='0')
            mint=mint.substr(1);

        int h=stoi(hour),m=stoi(mint)+1;
        
        while(true){
            if(m==60){
                m=0;
                h++;
            }
            
            if(h==24)
                h=0;
            
            if(checksatis(time,h,m)){
                res=process(h,m);
                return res;
            }
            
            m++;
        }
        
    }
};