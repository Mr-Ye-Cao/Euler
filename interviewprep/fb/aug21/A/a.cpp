class Solution {
public:
    int bulbSwitch(int n) {
        // 1 2 3 4 ..... n
        // 2^2 3^1
        // 1(0,0) 2(1,0) 4(2,0) 6(1,1) 12(2,1) 3
        // whether or not the # of factors is a multiple of 2
        
        // 1 2  
        // 1 2 3 4   1(2^0) 0 0 1(2^2)
        // 5 0
        // 6 (2^1 3^1)
        return sqrt(n);
    }
};