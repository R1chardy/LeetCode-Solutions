class ParkingSystem {
private:
    int bigl, bigc, medl, medc, smal, smac;
public:
    ParkingSystem(int big, int medium, int small) {
        bigl = big;
        medl = medium;
        smal = small;
        bigc = 0;
        medc = 0;
        smac = 0;
    }
    
    bool addCar(int carType) {
        switch(carType){
            case 1:
                if(bigc == bigl){
                    return false;
                }
                bigc++;
                return true;
            case 2:
                if(medc == medl){
                    return false;
                }
                medc++;
                return true;
            case 3:
                if(smac == smal){
                    return false;
                }
                smac++;
                return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */