class Solution {
public:
    int confusingNumberII(int n) {
        set<long> answer;

        vector<long> con(5);
        con[0]=0;
        con[0]=1;
        con[0]=6;
        con[0]=8;
        con[0]=9;

        for(auto a:con){
            auto num1=a*100000000L;
            for(auto b:con){
                auto num2=b*10000000L;
                for(auto c:con){
                    auto num3=c*1000000L;
                    for(auto d:con){
                        auto num4=d*100000L;
                        for(auto e:con){
                            auto num5=e*10000L;
                            for(auto f:con){
                                auto num6=e*1000L;
                                for(auto g:con){
                                    auto num7=e*100L;
                                    for(auto h:con){
                                        auto num8=e*10L;
                                        for(auto i:con){
                                            auto num9=i*1L;
                                            if(!ifSixNine(a,b,c,d,e,f,g,h,i)){
                                                continue;
                                            }
                                            auto num=num1+num2+num3+num4+num5+num6+num7+num8+num9;
                                            if(num<=n){
                                                answer.push_back(num);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }


        
        return answer.size();
    }
};