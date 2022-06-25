class Solution {
public:
    string removeDuplicates(string s) {
        while(true){
            if(s==""){
                return s;
            }

            int idx=-1;
            for(int i=0;i<s.length()-1;i++){
                if(s[i]==s[i+1]){
                    idx=i;
                    break;
                }
            }

            if(idx!=-1){
                int g=0,lidx=idx-g,ridx=idx+1+g;
                cout<<lidx<<" "<<ridx<<endl;
                for(;lidx>=0&&ridx<s.length();g++){
                    lidx=idx-g,ridx=idx+1+g;
                    cout<<lidx<<":"<<ridx<<endl;
                    if(s[lidx]!=s[ridx]){
                        s=s.substr(0,lidx+1)+s.substr(ridx);
                        break;
                    }
                    if(lidx==0){
                        cout<<ridx<<endl;
                        s=s.substr(ridx+1);
                        break;
                    }
                    if(ridx==s.length()-1){
                        s=s.substr(0,lidx);
                        break;
                    }
                }
            }else{
                return s;
            }
        }

    }
};