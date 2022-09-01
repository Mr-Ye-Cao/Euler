class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<tuple<double, int, int> > sorted;

        for(int i=0;i<points.size();i++){
            int x=points[i][0],y=points[i][1];
            double dis=sqrt(x*x + y*y);
            
            sorted.push_back(make_tuple(dis,x,y));
        }

        sort(sorted.begin(),sorted.end());
        vector<vector<int> > result;

        for(int i=0;i<k;i++){
            vector<int> r(2);
            int x=get<1>(sorted[i]), y=get<2>(sorted[i]);
            r[0]=x;r[1]=y;
            result.push_back(r);
        }

        return result;
    }
};