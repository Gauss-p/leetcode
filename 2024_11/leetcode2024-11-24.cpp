#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // 将所有列表的元素拆开，放到同一个列表中间，并从小到大排序，但是又因为题目要求区间中包含每个列表中至少一个元素，所以我们在拆开元素的同时把该元素归属的列表索引放到它后面，形成一个pair数对，这样在排序以后我们既可以获得原有的排序效果，又不会出现找不到元素所属列表的情况
        vector<pair<int, int>> tot;
        int n = nums.size();
        for (int i=0; i<n; i++){
            for (auto& j : nums[i]){
                tot.emplace_back(j, i); // 元素后添加其所属列表索引
            }
        }
        sort(tot.begin(), tot.end());
        vector<int> res = {100000, 300000}; // 这样初始化可以直接进行之后的运算
        int l = 0, r = 0, cnt = 0; // cnt统计一共出现了几个列表序号
        unordered_map<int, int> mp; // 统计每一个列表序号出现的次数，用于去重
        for (; r<tot.size(); r++){
            mp[tot[r].second]++;
            if (mp[tot[r].second] == 1){
                // cnt用来去重，只在某一个列表序号第一次出现的时候统计
                cnt++;
            }
            if (cnt == n){
                // [l,r]中的元素已经包含了nums中每一个列表至少一个元素
                // 此时窗口左边可能有多个元素在一个列表中，需要修改左端点
                while (mp[tot[l].second] > 1){
                    // 如果窗口中存在多个左端点对应元素的列表序号，右移左端点
                    mp[tot[l].second]--;
                    l++;
                }
                if (res[1]-res[0] > tot[r].first-tot[l].first || (res[1]-res[0] == tot[r].first-tot[l].first && res[0] > tot[l].first)){
                    // 按照题目要求，更新最小区间
                    res[0] = tot[l].first;
                    res[1] = tot[r].first;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    vector<int> res = s.smallestRange(nums);
    cout << res[0] << " " << res[1] << endl;
}
