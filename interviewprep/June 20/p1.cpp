class Solution {
public:
    bool containsRot(int i,int j,int k,int l){
        if(i==2 || i==5 || i==6 || i==9){
            return true;
        }
        if(j==2 || j==5 || j==6 || j==9){
            return true;
        }
        if(k==2 || k==5 || k==6 || k==9){
            return true;
        }
        if(l==2 || l==5 || l==6 || l==9){
            return true;
        }

        return false;
    }

    int rotatedDigits(int n) {
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        v.push_back(2);
        v.push_back(5);
        v.push_back(6);
        v.push_back(8);
        v.push_back(9);

        set<int> choices;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                for(int k=0;k<v.size();k++){
                    for(int l=0;l<v.size();l++){
                        int num=v[i]*1000+v[j]*100+v[k]*10+v[l];
                        if(num<=n && containsRot(v[i],v[j],v[k],v[l])){
                            choices.insert(num);
                        }
                    }
                }
            }
        }

        return choices.size();
    }
};