#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<long long>> t;
    void maintain(int o){
        int l = o*2, r = o*2+1;
        t[o][0] = max(t[l][0]+t[r][2], t[l][1]+t[r][0]);
        t[o][1] = max(t[l][0]+t[r][3], t[l][1]+t[r][1]);
        t[o][2] = max(t[l][2]+t[r][2], t[l][3]+t[r][0]);
        t[o][3] = max(t[l][2]+t[r][3], t[l][3]+t[r][1]);
    }
    void build(int o, int l, int r, vector<int>& nums){
        if (l == r){
            // 到了叶子节点
            t[o][3] = max(nums[l], 0);
            return;
        }
        int m = (l+r)/2;
        // 分别初始化左孩子和右孩子
        build(o*2, l, m, nums);
        build(o*2+1, m+1, r, nums);
        maintain(o); // 每次结束都要刷新一遍节点o的值
    }
    void update(int o, int l, int r, int i, int value){
        if (l == r){
            // 查到叶子节点，直接更新
            t[o][3] = max(value, 0);
            return;
        }
        int m = (l+r)/2;
        // 否则用二分更新
        if (i <= m){
            update(o*2, l, m, i, value);
        }
        else{
            update(o*2+1, m+1, r, i, value);
        }
        maintain(o); // 每次结束都要刷新一遍节点o的值
    }
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        // 对于这道题目，我们首先定义F(A)表示数组A的最大和，接着，用线段树的思路，我们可以将数组nums分成两部分，我们称左边的一半是a，右边的一半是b，但是F(nums)并不能简单地表示为F(a)+F(b)，因为如果我们所选的恰好是a的最后一个和b的第一个元素，就和题意不符合了。这启示我们，可以通过选不选数组的第一个或最后一个数字来将F函数分成四种情况，第一种f00表示第一个和最后一个都不选，第二种f01表示第一个不选，最后一个可选可不选，第三种f10表示第一个可选可不选，最后一个不选，第四种f11表示第一个和最后一个都可选可不选。那么我们需要返回的答案就是f11(nums)
        // 接下来开始求递推式，也就是如果将一个数组a分成左右两边的p和q，那么四个f(a)的值分别是多少。我们可以发现f00(a)可以是f01(p)+f00(q)或者f00(p)+f10(q)，那么又因为我们要求最大和，所以就取两种情况的最大值即可。以此类推，我们可以得出四个式子：
        // f00(a) = max(f00(p)+f10(q), f01(p)+f00(q))
        // f01(a) = max(f00(p)+f11(q), f01(p)+f01(q))
        // f10(a) = max(f10(p)+f10(q), f11(p)+f00(q))
        // f11(a) = max(f10(p)+f11(q), f11(p)+f01(q))
        // 因为如果每次都重新写一遍太麻烦，我们可以定义一个函数maintain(o)用来更新线段树中节点o的值，里面写上这四个式子即可
        // 接下来我们需要更新每一个节点的值，所以可以用二分查找的方法更新，对于每一个区间，如果是叶子节点，那么直接将其更新为val即可，否则将其用中间位置分为两段，如果待更新节点在左边区间，就继续往左边区间查，否则就往右边查
        // 同时我们需要一个初始化函数，它只负责将所有叶子节点置为nums中原先的值，并将所有非叶子节点用maintain函数进行更新即可
        int n = nums.size();
        t.resize(1<<(32-__builtin_clz(n)+1), vector<long long>(4, 0));
        build(1, 0, n-1, nums); // 初始化
        long long res = 0;
        for (auto &q : queries){
            int tmpI = q[0], tmpVal = q[1];
            update(1, 0, n-1, tmpI, tmpVal); // 更新
            res += t[1][3];
        }
        int modNum = 1e9+7;
        return (res%modNum+modNum)%modNum;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,5,9};
    vector<vector<int>> queries = {{1,-2},{0,-3}};
    cout << s.maximumSumSubsequence(nums, queries) << endl;
}
