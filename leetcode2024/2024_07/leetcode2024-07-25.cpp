#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int res = INT_MAX;
        bool flag = false;
        bool first_0 = false, first_5 = false;
        for (int i=n-1; i>=0; i--){
            if ((first_0 && (num[i] == '0' || num[i] == '5')) || (first_5 && (num[i] == '2' || num[i] == '7'))){
                return n-i-2;
            }
            if (num[i] == '0'){
                first_0 = true;
                flag = true;
            }
            if (num[i] == '5'){
                first_5 = true;
            }
        }
        return flag ? n-1 : n;
        // int cnt = 0;
        // for (int i=n-1; i>=0; i--){
        //     if (cnt == 2) break;
        //     if (num[i] == '0'){
        //         flag = true;
        //         for (int j=i-1; j>=0; j--){
        //             if (num[j] == '0' || num[j] == '5'){
        //                 res = min(res, (i-j-1)+(n-i-1));
        //                 cnt++;
        //             }
        //         }
        //     }
        //     if (num[i] == '5'){
        //         for (int j=i-1; j>=0; j--){
        //             if (num[j] == '2' || num[j] == '7'){
        //                 res = min(res, (i-j-1)+(n-i-1));
        //                 cnt++;
        //             }
        //         }
        //     }
        // }
        if (res == INT_MAX){
            return flag ? n-1 : n;
        }
        return res;
    }
    long long minimumOperations2(vector<int>& nums, vector<int>& target) {
        // 首先将target中的每一个值与nums中相减，求得一个差值数组sub，再对sub求差分数组，要将nums变为target，也就是要将sub中所有元素变为0，同时只需要对其中一些值进行加1或减1操作，那么我们求出需要进行多次加1操作的数字，将需要添加的所有1累加入res即可
        int n = nums.size();
        vector<int> sub(n+2, 0);
        for (int i=0; i<n; i++){
            sub[i+1] = target[i]-nums[i];
            // cout << sub[i+1] << " ";
        }
        // cout << sub[n+1] << " ";
        // cout << endl;
        long long res = 0;
        for (int i=1; i<n+2; i++){
            if (sub[i]-sub[i-1]>0){
                res += sub[i]-sub[i-1];
            }
        }
        return res;
    // long long my_cal(vector<int> nums, int i, int j){
    //     long long res = 0;
    //     int cnt = 1;
    //     vector<int> v = nums;
    //     sort(v.begin(), v.end());
    //     for (int k=i; k<j; k++){
    //         vector<int> tmp;
    //         for (int l=i; l<j; l++){
    //             if (nums[l] == v[k]){
    //                 tmp.push_back(l);
    //             }
    //         }
    //         if (tmp.size() == 1 && tmp[0]!=i && tmp[0]!=j-1) cnt++;
    //         for (int l=0; l<tmp.size()-1; l++){
    //             if (tmp[l+1] != tmp[l] + 1){
    //                 if (tmp[l] == i && tmp[l+1] == j-1){
    //                     continue;
    //                 }
    //                 cnt++;
    //             }
    //         }
    //         res += v[k] * cnt;
    //     }
    //     return res;
    // }
    // long long minimumOperations(vector<int>& nums, vector<int>& target) {
    //     int n = nums.size();
    //     int i=0;
    //     int res = 0;
    //     for (int j=0; j<n; j++){
    //         nums[j] = target[j]-nums[j];
    //     }
    //     while (i < n){
    //         int tmp_max = 0, j = i;
    //         if (nums[i] == 0){
    //             i++;
    //             continue;
    //         }
    //         while (j < n && ((nums[j]>0 && nums[i]>0) || (nums[j]<0 && nums[i]<0))){
    //             tmp_max = max(tmp_max, abs(nums[j]));
    //             j++;
    //         }
    //         i = j;
    //         res += tmp_max;
    //     }
    //     return res;
        // ----------------------------------------------------------------------------
        // while (i < n){
        //     int tmp = target[i]-nums[i];
        //     if (tmp == 0){
        //         i++;
        //         continue;
        //     }
        //     int j=i;
        //     while (j < n && ((target[j]-nums[j] > 0 && tmp > 0) || (target[j]-nums[j] < 0 && tmp < 0))){
        //         nums[j] += tmp;
        //         j++;
        //     }
        //     i++;
        //     res += abs(tmp);
        // }
        // return res;
    }
};

int main(){
    Solution s;
    string num = "2245047";
    cout << s.minimumOperations(num) << endl;
    vector<int> nums = {1,1,3,4}, target = {4,1,3,2};
    cout << s.minimumOperations2(nums, target) << endl;
}
