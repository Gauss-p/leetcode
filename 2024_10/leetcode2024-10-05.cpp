#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        auto cal = [&](long long runTime){
            long long res = 0;
            for (auto& i : time){
                res += runTime/(1ll*i);
            }
            return res < totalTrips;
        };
        long long l = 1, r = *max_element(time.begin(), time.end())*1ll*totalTrips;
        while (l < r){
            long long mid = (l+r)/2;
            if (cal(mid)){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return r;
    }
};

int main(){
    Solution s;
    vector<int> time = {1,3,2};
    int totalTrips = 5;
    cout << s.minimumTime(time, totalTrips) << endl;
}
