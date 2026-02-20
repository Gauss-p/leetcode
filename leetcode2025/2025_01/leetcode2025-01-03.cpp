#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class MyCalendarTwo {
private:
    unordered_map<int, int> tree, lazy;
public:
    MyCalendarTwo() {
        
    }

    void update(int start, int end, int l, int r, int indx, int op){
        if (r<start || end<l){
            return;
        }
        if (start<=l && r<=end){
            tree[indx] += op;
            lazy[indx] += op;
        }
        else{
            int mid = (l+r)/2;
            update(start, end, l, mid, indx*2, op);
            update(start, end, mid+1, r, indx*2+1, op);
            tree[indx] = lazy[indx]+max(tree[indx*2], tree[indx*2+1]);
        }
    }
    
    bool book(int startTime, int endTime) {
        update(startTime, endTime-1, 0, 1e9, 1, 1);
        if (tree[1] > 2){
            update(startTime, endTime-1, 0, 1e9, 1, -1);
            return false;
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */

int main(){
    MyCalendarTwo mc;
    vector<vector<int>> booked = {{10,20},{50,60},{10,40},{5,15},{5,10},{25,55}};
    for (auto b : booked){
        cout << mc.book(b[0], b[1]) << endl;
    }
}
