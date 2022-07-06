/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int n;
    int tt;
    unordered_map<int,int> cache;
    int ans;

    int getval(int idx,MountainArray &mountainArr){
        if(idx<0||idx>=n){
            return INT_MIN;
        }else if(cache.find(idx)!=cache.end()){
            return cache[idx];
        }else{
            cache[idx]=mountainArr.get(idx);
            return cache[idx];
        }
    }

    int findpeak(MountainArray &mountainArr){
        int l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;

            int mv=getval(m,mountainArr),lv=getval(m-1,mountainArr),rv=getval(m+1,mountainArr);

            if(mv==tt){
                ans=min(ans,m);
            }
            if(lv==tt){
                ans=min(ans,m-1);
            }
            if(rv==tt){
                ans=min(ans,m+1);
            }
            
            if(mv>lv&&mv>rv){
                return m;
            }else if(mv<lv){
                r=m-1;
            }else{
                l=m+1;
            }
        }

        return -1;
    }

    int f(int l,int r,bool isup,MountainArray &mountainArr){
        if(l>r){
            return INT_MAX;
        }
        int m=l+(r-l)/2,mv=getval(m,mountainArr);
        // cout<<isup<<" "<<mv<<" "<<tt<<endl;

        if(mv==tt){
            return m;
        }

        if(isup){
            if(mv<tt){
                return f(m+1,r,isup,mountainArr);
            }else{
                return f(l,m-1,isup,mountainArr);
            }
        }else{
            if(mv<tt){
                return f(l,m-1,isup,mountainArr);
            }else{
                return f(m+1,r,isup,mountainArr);
            }
        }
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        n=mountainArr.length();
        tt=target;
        ans=INT_MAX;

        int clm=findpeak(mountainArr);
        
        int lt=f(0,clm-1,true,mountainArr);
        int rt=f(clm+1,n-1,false,mountainArr);

        cout<<lt<<endl;
        cout<<rt<<endl;

        
        ans=min(lt,ans);
        ans=min(rt,ans);
        
        if(ans==INT_MAX){
            return -1;
        }

        return ans;
    }
};