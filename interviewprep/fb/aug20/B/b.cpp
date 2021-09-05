class Solution {
public:
    int smallestFactorization(int num) {
        if(num==1)
            return 1;
        bool facd;
        unordered_map<int,int> factor;
        
        factor[2]=0;
        factor[3]=0;
        factor[5]=0;
        factor[7]=0;
        
        while(num!=1){
            facd=false;
            for(auto pa:factor){
                if(num%pa.first==0){
                    facd=true;
                    num/=pa.first;
                    factor[pa.first]++;
                    break;
                }
            }
            if(!facd)
                return 0;
        }
        
        vector<int> res;
        
        for(int i=0;i<factor[5];i++)
            res.push_back(5);
        
        for(int i=0;i<factor[7];i++)
            res.push_back(7);
        
        
        //  priority one: if a number can be grouped
        //  then it should be grouped
        if(factor[2]>2){
            int numei=factor[2]/3;
            for(int i=0;i<numei;i++)
                res.push_back(8);
            factor[2]%=3;
        }
        
        //  now no matter how we group number, it would always
        //  spend 2 number at a time
        //  therefore the number of digits will be fixed
        //  therefore, we should greedily maximize the end digits
        //  so as to minimize the starting digits
        
        // to do that, we start by grouping 3s together
        // so that 2s will be left for beginning
        if(factor[3]>1){
            int numni=factor[3]/2;
            for(int i=0;i<numni;i++)
                res.push_back(9);
            factor[3]%=2;
        }
        
        // now we will group 2 and 3 together
        if(factor[3]==1){
            if(factor[2]>0){
                res.push_back(6);
                factor[3]=0;
                factor[2]--;
            }else{
                res.push_back(3);
                factor[3]=0;
            }
        }
        
        // now we group 2s together
        if(factor[2]==2){
            res.push_back(4);
        }else if(factor[2]==1){
            res.push_back(2);
        }
        
        std::sort(res.begin(),res.end());
        if(res.size()>10)
            return 0;
        
        long long re=0;
        long long fa=1;
        for(int i=res.size()-1;i>=0;i--){
            re+=fa*res[i];
            fa*=10;
        }
        
        if(re>2147483647)
            return 0;
        else
            return re;
    }
};