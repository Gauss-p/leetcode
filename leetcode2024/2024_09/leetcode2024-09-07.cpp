#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // 我们称全数组中相邻两数不同的数量为k的数组为k-数组，例如：
        // [1,2,1]就是2-数组，[1,2,1,1,3]就是3-数组
        // 在nums中循环x，然后从k到0循环j，其中x就是待加入的数字，而j就是加入x以后要凑成j-数组的最大长度，那么我们可以知道，对于每一个数字x，有两种可能的操作，第一种是将其加到上一个与其相同的数字后面，第二种就是将其加到上一个不同的数字上面，最终凑成j-数组
        // 所以，对于cnt[j][x]，第一种方案就是找到上一个与x相同的数字，计算连接x以后的长度，即cnt[j][x]+1，第二种方案就是找到不同于x的数字，计算连接x以后的长度，这时候我们还需要计算另外一个数组mx，其中mx[j]表示的就是nums中(j-1)-数组的最大长度，所以第二种方案的答案就是mx[j-1]+1(需保证j>0)，两种方案求最大值即可
        vector<unordered_map<int, int>> cnt(k+1);
        vector<int> mx(k+1, 0);
        for (int x : nums){
            for (int j=k; j>=0; j--){
                cnt[j][x] = cnt[j][x]+1; // 第一种方案，连接上一个与x相同的数字
                if (j > 0 && cnt[j][x] < mx[j-1]+1){
                    cnt[j][x] = mx[j-1]+1; // 第二种方案，连接上一个与x不同的数字
                }
                if (mx[j] < cnt[j][x]){
                    mx[j] = cnt[j][x]; // 计算j-数组的最大长度
                }
            }
        }
        return *max_element(mx.begin(), mx.end());
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,1,1,3};
    int k = 2;
    cout << s.maximumLength(nums, k) << endl;
}
