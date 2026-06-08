#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res;
        int indx1 = 0, indx2 = 0;
        for (int i : nums){
            if (i < pivot){
                res.insert(res.begin()+indx1, i);
                indx1++;
                indx2++;
            }
            else if (i == pivot){
                res.insert(res.begin()+indx2, i);
                indx2++;
            }
            else{
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {9,12,5,10,14,3,10};
    int pivot = 10;
    vector<int> res = s.pivotArray(nums, pivot);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
