class RideSharingSystem {
public:
    queue<int>rideer;
    queue<int>driver;
    unordered_set<int>cancel;
    unordered_set<int>active;
    
    RideSharingSystem() {   
    }
    
    void addRider(int riderId) {
        rideer.push(riderId);
        active.insert(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
        
    }
    
    vector<int> matchDriverWithRider() {
        while(!rideer.empty()&&(!active.count(rideer.front())||cancel.count(rideer.front()))){
            rideer.pop();
        }
        int a=rideer.size();
        if(!rideer.empty()&&!driver.empty()){
            int i=driver.front();
            int j=rideer.front();
            active.erase(j);
            cancel.erase(i);
            driver.pop();
            rideer.pop();
            return {i,j};
        }
        return{-1,-1};
        
    }
    
    void cancelRider(int riderId) {
       if(active.count(riderId)){
           active.erase(riderId);
           cancel.insert(riderId);
       }
        
        
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
