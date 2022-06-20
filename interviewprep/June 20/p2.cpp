class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
    	int n=seats.size();
        vector<int> dpl(n,0);
        vector<int> dpr(n,0);
        vector<int> nn(n,INT_MAX);

        for(int i=0;i<n;i++){
        	if(i==0){
        		if(seats[i]==0){
        			dpl[i]=1000000;
        		}else{
        			dpl[i]=0;
        		}
        		continue;
        	}

        	if(seats[i]==0){
        		// empty
        		if(seats[i-1]==1000000){
        			seats[i]=1000000;
        		}else{
        			dpl[i]=dpl[i-1]+1;
        		}
        	}else{
        		// taken
        		dpl[i]=0;
        	}
        }

        for(int i=n-1;i>=0;i--){
        	if(i==n-1){
        		if(seats[i]==0){
        			dpr[i]=1000000;
        		}else{
        			dpr[i]=0;
        		}
        		continue;
        	}

        	if(seats[i]==0){
        		// empty
        		if(seats[i+1]==1000000){
        			dpr[i]=1000000;
        		}else{
        			dpr[i]=dpr[i+1]+1;
        		}
        	}else{
        		// taken
        		dpr[i]=0;
        	}
        }

        for(int i=0;i<n;i++){
        	nn[i]=min(dpl[i],dpr[i]);
        }

        int result=INT_MIN;
        for(int i=0;i<n;i++){
        	result=max(result,nn[i]);
        }

        if(result==1000000){
        	return n;
        }

        return result;
    }
};