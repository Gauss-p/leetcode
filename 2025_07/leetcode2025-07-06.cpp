#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class FindSumPairs {
private:
    vector<int> NUMS1, NUMS2;
    unordered_map<int, int> cnt1, cnt2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        NUMS1 = nums1;
        NUMS2 = nums2;
        for (int i : nums1){
            cnt1[i]++;
        }
        for (int i : nums2){
            cnt2[i]++;
        }
    }
    
    void add(int index, int val) {
        cnt2[NUMS2[index]]--;
        NUMS2[index] += val;
        cnt2[NUMS2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for (auto&kv : cnt1){
            if (cnt2.count(tot-kv.first)){
                res += kv.second*cnt2[tot-kv.first];
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums1 = {1,1,2,2,2,3}, nums2 = {1,4,5,2,5,4};
    vector<string> ops = {"count","add","count","count","add","add","count"};
    vector<vector<int>> vals = {{7},{3,2},{8},{4},{0,1},{1,1},{7}};
    FindSumPairs fsp(nums1, nums2);
    for (int i=0; i<ops.size(); i++){
        if (ops[i] == "count"){
            cout << fsp.count(vals[i][0]) << endl;
        }
        else{
            fsp.add(vals[i][0], vals[i][1]);
        }
    }
}
