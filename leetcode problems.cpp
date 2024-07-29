#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution2411 {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<pair<int, int>> v;// 可以在循环中不断维护v[0]，使得：
        // v[0].first为：以当前i为左端点，可以得到最大子数组按位或值
        // v[0].second为：以当前i为左端点，能够达到最大子数组按位或值的最小右端点
        // 这是为了保证子数组的长度要尽可能的小
        for (int i=n-1; i>=0; i--){
            v.emplace_back(0, i);
            for (int j=0; j<(int)v.size(); j++){
                // 每进一个数据，就将之前所有元素和它相或
                v[j].first |= nums[i];
            }
            // 下面开始维护数组v，即去重操作，对于重复的或值，只需要保存右端点最小的那一个
            // 如果或值不同，则需要原地将后面不同的或值平移到当前k+1指定的位置
            int k=0;
            for (int j=1; j<(int)v.size(); j++){
                if (v[j].first != v[k].first){
                    v[++k] = v[j];
                }
                else{
                    v[k].second = v[j].second;
                }
            }
            // 最终重新定义v的大小，将k之后的所有重复的值删掉
            v.resize(k+1);
            // 同时将答案保存
            res[i] = v[0].second-i+1;
        }
        return res;
    }
};

class Solution26 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for (int i=0; i<n; i++){
            if (nums[i] != nums[j]){
                nums[j+1] = nums[i];
                j++;
            }
        }
        return j+1;
    }
};

class Solution2269 {
public:
    int divisorSubstrings(int num, int k) {
        int tmp = 0, res = 0;
        string s_num = to_string(num);
        for (int i=0; i<(int)s_num.size(); i++){
            tmp = tmp*10+(s_num[i]-'0');
            if (i < k-1) continue;
            if (tmp != 0 && num%tmp == 0){
                res++;
            }
            tmp = tmp%((int)pow(10, k-1));
        }
        return res;
    }
};

int main(){
    // Solution2411 s2411;
    // vector<int> nums = {1,0,2,1,3};
    // vector<int> res = s2411.smallestSubarrays(nums);
    // for (int i : res) cout << i << " ";
    // cout << endl;
    // -----------------------------------------------------------------
    // Solution26 s26;
    // nums = {1,1,2};
    // cout << s26.removeDuplicates(nums) << endl;
    // -----------------------------------------------------------------
    Solution2269 s2269;
    int num = 240, k = 2;
    cout << s2269.divisorSubstrings(num, k) << endl;
}
