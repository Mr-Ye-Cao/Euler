class ParkingSystem {
public:
    int bigslot;
    int mediumslot;
    int smallslot;
    
    ParkingSystem(int big, int medium, int small) {
        bigslot=big;
        mediumslot=medium;
        smallslot=small;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(bigslot>0){
                bigslot--;
                return true;
            }
            return false;
        }else if(carType==2){
            if(mediumslot>0){
                mediumslot--;
                return true;
            }
            return false;
        }else{
            if(smallslot>0){
                smallslot--;
                return true;
            }
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */