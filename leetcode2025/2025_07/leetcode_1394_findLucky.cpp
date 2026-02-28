#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int i : arr){
            cnt[i]++;
        }
        int res = -1;
        for (auto&kv : cnt){
            if (kv.first == kv.second){
                res = max(res, kv.first);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {2,2,3,4};
    cout << s.findLucky(arr) << endl;
}
