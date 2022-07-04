class Logger {
public:
    unordered_map<string,int> tm;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(tm.find(message)==tm.end()){
            tm[message]=timestamp+10;
            return true;
        }else{
            if(tm[message]<=timestamp){
                tm[message]=timestamp+10;
                return true;
            }else{
                return false;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */