/**
 * 45 min Fuck me Merry Christmas
 * */

class Solution {
public:
    int divide(int did, int div) {
        //  divisor 2divisor 4divisor 8divisor 
        // 2^0 2^1 2^2 2^3 2^4 ....
        long long dividend=did;
        long long divisor=div;

        if(dividend==0)
            return 0;
        if(dividend==divisor)
            return 1;
        if(dividend==0-divisor)
            return -1;
        if(divisor==1)
            return dividend;
        if(divisor==-1&&dividend==-2147483648)
            return 2147483647;
        
        bool isN=false;
        
        if((dividend<0&&divisor>0)||(dividend>0&&divisor<0)){                   isN=true;
        }
        
        if(divisor<0){
            divisor=0-divisor;
        }
        if(dividend<0){
            dividend=0-dividend;
        }
        
        
        vector<pair<long long,int> > store;
        store.push_back(make_pair(divisor,1));
        
        while(store[store.size()-1].first<dividend){
            int v1,v2;
            if(store[store.size()-1].first>=1073741824)
                break;
            
    v1=store[store.size()-1].first+store[store.size()-1].first;
    v2=store[store.size()-1].second+store[store.size()-1].second;
            if(v1<store[store.size()-1].first||v1-store[store.size()-1].first!=store[store.size()-1].first){
                // overflows
                break;
            }
            store.push_back(make_pair(v1,v2));
        }
        
        if(store[store.size()-1].first>dividend)
            store.pop_back();
        
        int p=store.size()-1,res=0;
        while(p>=0){
            while(dividend-store[p].first>=0){
                res+=store[p].second;
                dividend-=store[p].first;
                // cout<<dividend<<"\n";
            }
            p--;
        }
        if(isN)
            return 0-res;
        else
            return res;
    }
};