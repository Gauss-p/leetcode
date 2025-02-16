#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int& i : arr) mp[i]++;
        for (auto&kv : mp){
            if (4*kv.second>arr.size()){
                return kv.first;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,2,6,6,6,6,7,10};
    cout << s.findSpecialInteger(arr) << endl;
}
