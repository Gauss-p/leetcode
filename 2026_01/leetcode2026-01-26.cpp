#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res = {};
        int minDiff = INT_MAX;
        for (int i=0; i<arr.size()-1; i++){
            int curDiff = arr[i+1]-arr[i];
            if (curDiff < minDiff){
                minDiff = curDiff;
                res = {{arr[i], arr[i+1]}};
            }
            else if (curDiff == minDiff){
                res.push_back({arr[i], arr[i+1]});
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {4,2,1,3};
    vector<vector<int>> res = s.minimumAbsDifference(arr);
    for (auto i : res){
        cout << i[0] << " " << i[1] << endl;
    }
}
