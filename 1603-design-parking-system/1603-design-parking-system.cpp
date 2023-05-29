class ParkingSystem {
public:
    // vector<vector<int>>alloc;
    int b,m,s;
    ParkingSystem(int big, int medium, int small) {
        // vector<vector<int>>
        // alloc.push_back()
        b=big;
        m=medium;
        s=small;
    }
    
    bool addCar(int ct) {
        if(ct==1){
            if(b>0){b--;return true;}
        }
        else if(ct==2){
            if(m>0){m--;return true;}
        }
       else if(ct==3){
            if(s>0){s--;return true;}
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */