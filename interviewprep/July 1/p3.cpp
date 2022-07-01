class Solution {
public:
    double dfs(unordered_map<string,vector<pair<string,double> > > g, string n1,string n2){
        queue<pair<string,double>> tovisit;
        tovisit.push(make_pair(n1,1.0));

        map<string,bool> visited;
        for(auto p:g){
            visited[p.first]=false;
        }
        visited[n1]=true;

        while(!tovisit.empty()){
            pair<string,double> p=tovisit.front();
            string n=p.first;

            tovisit.pop();
            vector<pair<string,double> > neighbors=g[n];
            for(pair<string,double> np :neighbors){
                if(np.first==n2){
                    return np.second*p.second;
                }else if(! visited[np.first]){
                    tovisit.push(make_pair(np.first,np.second*p.second));
                    visited[np.first]=true;
                }
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // directed graph
        // a->b b->c a->c
        // equations: edges values: weights transition: multiplication
        // dfs is sufficient

        unordered_map<string,vector<pair<string,double> > > g;

        for(int i=0;i<equations.size();i++){
            if(g.find(equations[i][0])==g.end()){
                vector<pair<string,double> > v;
                v.push_back(make_pair(equations[i][1],values[i]));
                g[equations[i][0]]=v;
            }else{
                g[equations[i][0]].push_back(make_pair(equations[i][1],values[i]));
            }
            if(g.find(equations[i][1])==g.end()){
                vector<pair<string,double> > v;
                v.push_back(make_pair(equations[i][0],1.0/values[i]));
                g[equations[i][1]]=v;
            }else{
                g[equations[i][1]].push_back(make_pair(equations[i][0],1.0/values[i]));
            }
        }

        vector<double> result;

        for(int i=0;i<queries.size();i++){
            string n1=queries[i][0],n2=queries[i][1];
            if(g.find(n1)==g.end()||g.find(n2)==g.end()){
                result.push_back(-1);
            }else if(n1==n2){
                result.push_back(1);
            }else{
                result.push_back(dfs(g,n1,n2));
            }
        }

        return result;
    }
};