#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int m = buses.size(), n = passengers.size();
        int indx = 0, tmp_capacity;
        // 按顺序让各个乘客上车，一直到最后一个能上车的乘客都上去了，就退出循环
        // 我们在退出循环时就可以得到第一个没能上车的乘客的索引以及最后一辆车还有几个空位
        for (int i=0; i<m; i++){
            tmp_capacity = capacity;
            while (indx < n && passengers[indx] <= buses[i] && tmp_capacity > 0){
                indx++;
                tmp_capacity--;
            }
        }
        indx--; // 因为indx是第一个不能上车的乘客，所以indx-1就是最后一个上车的乘客
        // 接下来我们就开始插队，如果最后一辆车还有空位，那么我们就从最后一辆车到达的时刻开始往前找，一直找到第一个不和其他人重复的时间。否则，我们就从最后一个上车的人开始往前找位置插队，只要能插进，就定下来了最晚时间
        int res;
        if (tmp_capacity > 0){
            res = buses[m-1];
        }
        else{
            res = passengers[indx];
        }
        set<int> st(passengers.begin(), passengers.end());
        while (st.count(res)){
            // 插队
            res--;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> buses = {20,30,10};
    vector<int> passengers = {19,13,26,4,25,11,21};
    int capacity = 2;
    cout << s.latestTimeCatchTheBus(buses, passengers, capacity) << endl;
}
