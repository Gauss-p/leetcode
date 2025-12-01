#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int N;
    vector<int> b;
    bool check(long long mid){
        long long tot = 0;
        for (int& i : b){
            tot += min((long long)i, mid);
        }
        return tot >= N*mid;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        N = n;
        b = batteries;
        
        long long l = 0, r = 0;
        for (int& i : batteries){
            r += i;
        }
        r /= n;
        while (l<=r){
            long long mid = (l+r)>>1;
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
    int n = 2;
    vector<int> batteries = {3,3,3};
    cout << s.maxRunTime(n, batteries) << endl;
}
