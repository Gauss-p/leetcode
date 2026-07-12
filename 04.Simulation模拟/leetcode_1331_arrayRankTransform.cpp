#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() == 0){
            return {};
        }
        vector<int> bk = arr;
        sort(bk.begin(), bk.end());
        unordered_map<int, int> rank;
        rank[bk[0]] = 0;
        int cur = 1;
        for (int i=1; i<bk.size(); i++){
            if (bk[i] != bk[i-1]){
                rank[bk[i]] = cur;
                cur++;
            }
        }
        vector<int> res;
        for (int i : arr){
            res.push_back(rank[i]+1);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {40,10,20,30};
    vector<int> res = s.arrayRankTransform(arr);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
