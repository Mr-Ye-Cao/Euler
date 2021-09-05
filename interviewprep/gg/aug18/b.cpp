class NumArray {
public:
    vector<int> bit;
    vector<int> num; 

    NumArray(vector<int>& nums) {
        bit.resize(nums.size()+1);
        num.resize(nums.size());

        for(int i=0;i<nums.size();i++)
            num[i]=nums[i];

        for(int i=0;i<nums.size();i++)
            bit[i+1]=nums[i];
        
        for(int i=1;i<=nums.size();i++){
            int p=i+(i&-i);
            while(p<=nums.size()){
                bit[p]+=nums[i-1];
                p+=p&-p;
            }
        }
    }
    
    void update(int index, int val) {
        int diff=val-num[index];
        num[index]=val;
        index++;
         
        while(index<=num.size()){
            bit[index]+=diff;
            index+=index&-index;
        }
    }
    
    int sumRange(int l, int r) {
        l++;
        r++;
        l--;

        int lv=0,rv=0;
        while(l>=1){
            lv+=bit[l];
            l-=l&-l;
        }
        while(r>=1){
            rv+=bit[r];
            r-=r&-r;
        }

        return rv-lv;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */