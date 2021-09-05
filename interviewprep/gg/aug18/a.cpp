class Solution {
public:
    void perm(vector<int> arr,vector<string>& per,string temp){
        if(arr.empty()){
            per.push_back(temp);
            return;
        }
        
        for(int i=0;i<arr.size();i++){
            temp+=std::to_string(arr[i]);
            int rec=arr[i];
            arr.erase(arr.begin()+i);
            
            perm(arr,per,temp);
            
            temp=temp.substr(0,temp.length()-1);
            arr.insert(arr.begin()+i,rec);
        }
    }
    
    string largestTimeFromDigits(vector<int>& arr) {
        string temp="";
        vector<string> per;
        vector<string> qualified;
        
        perm(arr,per,temp);
        
        for(string str:per){
            string f,s;
            f=str.substr(0,2);
            s=str.substr(2);
            if(f[0]=='0')
                f=f.substr(1);
            if(s[0]=='0')
                s=s.substr(1);
            if(stoi(f)<=23&&stoi(s)<=59){
                qualified.push_back(str);
            }
        }
        string res="";
        int cm=0;
        for(string str:qualified){
            string f,s;
            f=str.substr(0,2);
            s=str.substr(2);
            if(f[0]=='0')
                f=f.substr(1);
            if(s[0]=='0')
                s=s.substr(1);
            if(stoi(f)*60+stoi(s)>=cm){
                cm=stoi(f)*60+stoi(s);
                res=str;
            }
        }
        
        if(res=="")
            return res;
        
        return res.substr(0,2)+":"+res.substr(2);
    }
};