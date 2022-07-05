class ExamRoom {
public:
    int last;
    set<int> s;
    ExamRoom(int n) {
        last = n-1;
    }
    
    int seat() {
        if(s.empty()){  //if the set is empty, occupy the first seat
            s.insert(0);
            return 0;
        }
        
        //now we iterate over all the intervals
        //to check which interval produces the greatest difference
        
        int left=0, diff=INT_MIN, pos=-1;
        
        //if 0 is not in set then we have to check the interval [0, first occupied seat] also 
        //if this interval produces the maximum difference then the student must occupy the 0th seat
        if(s.find(0)==s.end()){
            if(*s.begin()>diff){
                diff = *s.begin();
                pos = 0;
            }
        }
        
        //this loop checks the intervals like [1st occupied seat, 2nd occupied seat],
        //[2nd occupied seat, 3rd occuspied seat]...[second last occupied seat, last occupied seat]
        //if an interval in this loop produces the maximum difference then the student must occupy the seat at the mid of the interval
        for(int right: s){
            if((right-left)/2>diff){
                diff=(right-left)/2;
                pos = left + (right-left)/2;
            }
            left = right;
        }
        
        //if the n-1th seat is not occupied then we have to check the interval [last occupied seat, n-1] as well
        //if this interval produces the maximum difference then the student must occupy the (n-1)th seat
        if(s.find(last)==s.end()){
            if(last-left>diff){
                diff = last-left;
                pos = last;
            }
        }
        s.insert(pos);
        return pos;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};