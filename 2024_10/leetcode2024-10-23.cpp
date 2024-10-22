#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> cnt;
        for (auto i : hours){
            cnt[i%24]++;
        }
        long long res = 0;
        res += 1ll*cnt[0]*(cnt[0]-1)/2;
        res += 1ll*cnt[12]*(cnt[12]-1)/2;
        for (int i=1; i<12; i++){
            res += 1ll*cnt[i]*cnt[24-i];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> hours = {12,12,30,24,24};
    cout << s.countCompleteDayPairs(hours) << endl;
}
