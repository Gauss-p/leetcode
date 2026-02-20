#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 1e7+1;
        auto check = [&](int mid){
            double time = 0;
            for (int i : dist){
                time = ceil(time);
                time += (double)i/mid;
            }
            return time <= hour;
        };
        while (l < r){
            int mid = (l+r)/2;
            if (check(mid)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l==1e7+1 ? -1 : l;
    }
};

int main(){
    Solution s;
    vector<int> dist = {1,3,2};
    double hour = 6;
    cout << s.minSpeedOnTime(dist, hour) << endl;
}
