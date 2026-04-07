class Robot {
private:
    int w, h, pos, tot;
public:
    Robot(int width, int height) {
        tot = 2*(width+height)-4;
        w = width;
        h = height;
        pos = 0;
    }
    
    void step(int num) {
        pos = (pos+num-1)%tot+1;
    }
    
    vector<int> getPos() {
        if (pos <= w-1){
            return {pos, 0};
        }
        else if (pos <= w+h-2){
            return {w-1, pos-w+1};
        }
        else if (pos <= 2*w+h-3){
            return {w-1-(pos-w-h+2), h-1};
        }
        return {0, h-1-(pos-2*w-h+3)};
    }
    
    string getDir() {
        if (pos <= w-1){
            return "East";
        }
        else if (pos <= w+h-2){
            return "North";
        }
        else if (pos <= 2*w+h-3){
            return "West";
        }
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
