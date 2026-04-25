#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    long long Side;
    int K, n;
    vector<long long> pos;
    bool check(long long mid){
        for (int i=0; i<n; i++){
            bool flag = true;
            int indx = i;
            long long first = pos[indx];
            for (int x=0; x<K-1; x++){
                long long last = pos[indx];
                indx = lower_bound(pos.begin(), pos.end(), last+mid)-pos.begin();
                if (4*Side-(pos[indx]-first) < mid){
                    flag = false;
                    break;
                }
            }
            if (flag){
                return true;
            }
        }
        return false;
    }
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        Side = 1ll*side;
        K = k;
        for (auto& p : points){
            int x = p[0], y = p[1];
            if (x == side || y == 0){
                pos.push_back(x+y);
            }
            else{
                pos.push_back(1ll*4*side-(x+y));
            }
        }
        n = pos.size();
        for (int i=0; i<n; i++){
            pos.push_back(pos[i]+1ll*4*side);
        }
        sort(pos.begin(), pos.end());

        long long l = 0, r = 1ll*4*side+1;
        while (l<=r){
            long long mid = (l+r)/2;
            if (check(mid)){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return r;
    }
};

int main(){
    Solution s;
    int side = 2;
    vector<vector<int>> points = {{0,2},{2,0},{2,2},{0,0}};
    int k = 4;
    cout << s.maxDistance(side, points, k) << endl;
}
