#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        for (int l=1; l<=n; l++){
            for (int i=0; i<n-l+1; i++){
                int cur_or = 0;
                for (int j=i; j<i+l; j++){
                    cur_or = cur_or | nums[j];
                    // cout << cur_or << " " << nums[j] << endl;
                }
                if (cur_or >= k){
                    return l;
                }
            }
        }
        return -1;
    }
};

class Solution2 {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int> rear(n);
        int score = 0;
        for (int i=n-1; i>0; i--){
            if (possible[i] == 0){
                score--;
            }
            else{
                score++;
            }
            rear[i] = score;
        }
        score = 0;
        for (int i=0; i<n-1; i++){
            if (possible[i] == 0){
                score--;
            }
            else{
                score++;
            }
            if (score > rear[i+1]){
                return i+1;
            }
        }
        return -1;
    }
};

class Solution3 {
public:
    int minimumSubarrayLength2(vector<int>& nums, int k) {
        // 有一个与其极为相似的题目，2411.按位或最大的最小子数组长度
        int n = nums.size();
        vector<pair<int, int>> v;
        // 可以在循环中不断维护v[0]，使得：
        // v[0].first为：以当前i为左端点，可以得到最大子数组按位或值
        // v[0].second为：以当前i为左端点，能够达到最大子数组按位或值的最小右端点
        // 这是为了保证子数组的长度要尽可能的小
        int res = INT_MAX;
        for (int i=n-1; i>=0; i--){
            v.emplace_back(0, i);
            // 每次进循环，都往v中添加一个元素
            int m = v.size();
            for (int j=0; j<m; j++){
                // 每进一个数据，就将之前所有元素和它相或
                // 同时进行判断，如果运算后比k大，那么就将答案和此时的长度求最小值
                v[j].first |= nums[i];
                if (v[j].first >= k){
                    // 求最小
                    res = min(res, v[j].second-i+1);
                }
            }
            // 下面开始维护数组v，即去重操作，对于重复的或值，只需要保存右端点最小的那一个
            // 如果或值不同，则需要原地将后面不同的或值平移到当前k+1指定的位置
            int k=0;
            for (int l=1; l<m; l++){
                if (v[l].first != v[k].first){
                    // 处理不同或值的情况
                    v[++k] = v[l];
                }
                else{
                    // 处理相同或值的情况
                    v[k].second = v[l].second;
                }
            }
            v.resize(k+1);
            // 最终重新定义v的大小，将k之后的所有重复的值删掉
        }
        return res==INT_MAX ? -1 : res;
    }
};

int main(){
    Solution1 s1;
    vector<int> nums = {1,2,3};
    int k = 2;
    cout << s1.minimumSubarrayLength(nums, k) << endl;
    // -----------------------------------------------------------------
    Solution2 s2;
    vector<int> possible = {1,0,1,0};
    cout << s2.minimumLevels(possible) << endl;
    // -----------------------------------------------------------------
    Solution3 s3;
    vector<int> nums2 = {2,1,8};
    int k2 = 10;
    cout << s3.minimumSubarrayLength2(nums2, k2) << endl;
}
