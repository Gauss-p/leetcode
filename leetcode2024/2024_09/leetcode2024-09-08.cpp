#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto i : nums){
            pq.push(i*i);
        }
        vector<int> res;
        while (!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

int main(){
    vector<int> nums = {-4,-1,0,3,10};
    Solution s;
    vector<int> res = s.sortedSquares(nums);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}

/*977. 有序数组的平方
给你一个按非递减顺序排序的整数数组nums，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
*/
