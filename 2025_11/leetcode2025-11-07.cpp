#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define LL long long

class Solution {
private:
    int n, KK, radius;
    vector<LL> cityElectric;
    bool check(LL mid){
        int sumDiff = 0;
        vector<int> diff(n+1, 0);
        int used = 0;
        for (int i=0; i<n; i++){
            sumDiff += diff[i];
            LL curPower = sumDiff+cityElectric[i];
            if (curPower < mid){
                int sub = mid-curPower;
                used += sub;
                if (used > KK){
                    return false;
                }
                sumDiff += sub;
                int curRight = min(n-1, i+2*radius);
                diff[curRight+1] -= sub;
            }
        }
        return true;
    }
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        radius = r;
        KK = k;
        n = stations.size();
        vector<LL> preSum(n+1, 0);
        for (int i=0; i<n; i++){
            preSum[i+1] = preSum[i] + stations[i];
        }
        LL mn = LLONG_MAX;
        cityElectric.resize(n, 0);
        for (int i=0; i<n; i++){
            int left = max(0, i-r);
            int right = min(n-1, i+r)+1;
            cityElectric[i] = preSum[right]-preSum[left];
            mn = min(mn, cityElectric[i]);
        }

        // LL left = mn, right = *max_element(cityElectric.begin(), cityElectric.end())+k;
        LL left = mn, right = mn+k+1;
        LL res = 0;
        while (left <= right){
            LL mid = (left+right)/2;
            if (check(mid)){
                res = mid;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> stations = {1,2,4,5,0};
    int r=1, k=2;
    cout << s.maxPower(stations, r, k) << endl;
}
