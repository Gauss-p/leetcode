#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> subArray(n, 0); // 差分数组
        subArray[0] = nums[0];
        for (int i=1; i<n; i++){
            subArray[i] = nums[i]-nums[i-1];
        }
        int cnt = 0;
        vector<int> res(n-k+1, -1);
        for (int i=0; i<n; i++){
            // 滑动窗口
            if (subArray[i] == 1) cnt++;
            if (i < k-1) continue;
            if (subArray[i-k+1] == 1){
                // 不用在意长度为k的子数组的开头所对应的差分数组中的数是否为1
                cnt--;
            }
            if (cnt == k-1){
                res[i-k+1] = nums[i];
            }
            // 因为上面已经去除第一个数，所以不用再去除一遍，直接进入下一次统计即可
        }
        return res;
        // -------------------------------------------
        // int n = nums.size();
        // vector<int> res(n-k+1, -1);
        // vector<int> tmp;
        // for (int i=0; i<n; i++){
        //     tmp.push_back(nums[i]);
        //     if (i < k-1){
        //         continue;
        //     }
        //     bool flag = true;
        //     for (int j=1; j<k; j++){
        //         if (tmp[j-1]+1 != tmp[j]){
        //             flag = false;
        //             break;
        //         }
        //     }
        //     // cout << flag << endl;
        //     if (flag){
        //         res[i-k+1] = tmp[k-1];
        //     }
        //     tmp.erase(tmp.begin());
        // }
        // return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,3,2,5};
    int k = 3;
    vector<int> res = s.resultsArray(nums, k);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
