#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class MyCalendar {
private:
    unordered_set<int> tree, lazy; 
public:
    MyCalendar() {
        
    }

    bool query(int start, int end, int l, int r, int indx){
        if (r<start || end<l){
            return false;
        }
        if (lazy.count(indx)){
            return true;
        }
        if (start<=l && r<=end){
            return tree.count(indx);
        }
        int mid = (l+r)/2;
        return query(start, end, l, mid, indx*2) || query(start, end, mid+1, r, indx*2+1);
    }

    void update(int start, int end, int l, int r, int indx){
        if (r<start || end<l){
            return;
        }
        if (start<=l && r<=end){
            tree.insert(indx);
            lazy.insert(indx);
        }
        else{
            int mid = (l+r)/2;
            update(start, end, l, mid, indx*2);
            update(start, end, mid+1, r, indx*2+1);
            tree.insert(indx);
            if (lazy.count(indx*2) && lazy.count(indx*2+1)){
                lazy.insert(indx);
            }
        }
    }
    
    bool book(int startTime, int endTime) {
        if (query(startTime, endTime-1, 0, 1e9, 1)){
            return false;
        }
        update(startTime, endTime-1, 0, 1e9, 1);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */

int main(){
    MyCalendar mc;
    vector<vector<int>> booked = {{10,20},{15,25},{20,30}};
    for (auto b : booked){
        cout << mc.book(b[0], b[1]) << endl;
    }
}
