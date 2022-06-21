class Solution {
    public int kEmptySlots(int[] bulbs, int k) {
        TreeSet<Integer>set=new TreeSet<>();
        int n=bulbs.length;
        for(int i=0;i<n;i++){
            if(solver(set,bulbs[i],k)){
                return i+1;
            }
            set.add(bulbs[i]);
        }
        return -1;
    }
    
    public boolean solver(TreeSet<Integer>set,int index,int k){
        Integer floorValue=set.floor(index);
        // find in previous days the greatest bulb opened that is smaller than builb[i]
        if(floorValue!=null && floorValue!=index && index-floorValue-1==k){
            // if difference is exactly k
            return true;
        }
        
        // find in previous days the smallest bulb opened that is greater than builb[i]
        Integer ceilValue=set.ceiling(index);
        if(ceilValue!=null && ceilValue!=index && ceilValue-index-1==k){
            return true;
        }
        return false;
        
    }
}