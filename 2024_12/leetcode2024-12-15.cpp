#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int i : arr){
            cnt[i]++;
        }
        vector<int> cnts;
        for (auto& kv : cnt){
            cnts.push_back(kv.second);
        }
        sort(cnts.begin(), cnts.end(), greater<int>());
        int res = 0, tot = 0;
        for (int i : cnts){
            res++;
            tot += i;
            if (tot >= arr.size()/2){
                break;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {3,3,5,5,5,3,3,2,7,2};
    cout << s.minSetSize(arr) << endl;
}
