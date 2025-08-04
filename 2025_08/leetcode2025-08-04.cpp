#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> cnt;
        int res = 0;
        int l = 0;
        for (int r=0; r<n; r++){
            cnt[fruits[r]]++;
            while (cnt.size() > 2){
                cnt[fruits[l]]--;
                if (cnt[fruits[l]] == 0){
                    cnt.erase(fruits[l]);
                }
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> fruits = {0,1,2,1};
    cout << s.totalFruit(fruits) << endl;
}
