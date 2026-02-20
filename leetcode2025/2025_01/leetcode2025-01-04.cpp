#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class MyCalendarThree {
private:
    unordered_map<int, int> tree, lazy;
public:
    MyCalendarThree() {
        
    }

    void update(int start, int end, int l, int r, int indx){
        if (r<start || end<l){
            return;
        }
        if (start<=l && r<=end){
            tree[indx]++;
            lazy[indx]++;
        }
        else{
            int mid = (l+r)/2;
            update(start, end, l, mid, indx*2);
            update(start, end, mid+1, r, indx*2+1);
            tree[indx] = lazy[indx]+max(tree[indx*2], tree[indx*2+1]);
        }
    }
    
    int book(int startTime, int endTime) {
        update(startTime, endTime-1, 0, 1e9, 1);
        return tree[1];
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */

int main(){
    MyCalendarThree mc;
    vector<vector<int>> booked = {{10,20},{50,60},{10,40},{5,15},{5,10},{25,55}};
    for (auto b : booked){
        cout << mc.book(b[0], b[1]) << endl;
    }
}
