#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;
        for (int& i : nums1) mp1[i]++;
        for (int& i : nums2) mp2[i]++;
        vector<int> res;
        for (auto&kv : mp1){
            int k=kv.first, v=kv.second;
            for (int i=0; i<min(v, mp2[k]); i++){
                res.push_back(k);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
    vector<int> res = s.intersect(nums1, nums2);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
