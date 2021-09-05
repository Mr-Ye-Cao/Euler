/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int m,n,res=100000;
        m=binaryMatrix.dimensions()[0];
        n=binaryMatrix.dimensions()[1];

        for(int i=0;i<m;i++){
            if(binaryMatrix.get(i,0)==1)
                return 0;
            
            if(binaryMatrix.get(i,n-1)==0)
                continue;
            
            // binary search
            int s=1,e=n-1;
            while(s<=e){
                int mid=s+(e-s)/2;
                int v=binaryMatrix.get(i,mid);
                if(v==0){
                    s=mid+1;
                }else{
                    res=min(res,mid);
                    e=mid;
                }
                if(s==e)
                    break;
            }
        }
        
        return res==100000?-1:res;
    }
};