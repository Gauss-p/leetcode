#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i=0; i<n; i++){
            mp[nums[i]] = 1;
        }
        for (int i=0; i<(int)moveFrom.size(); i++){
            if (moveFrom[i] != moveTo[i]){
                mp[moveTo[i]] = 1;
                mp[moveFrom[i]] = 0;
            }
        }
        vector<int> res;
        for (auto &kv : mp){
            if (kv.second != 0){
                res.push_back(kv.first);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
    int minChanges(vector<int>& nums, int k) {
        // ������Բ��ò������ķ�������������ȣ����ǿ��Զ�ÿһ�����Խ��д���ʹ����ߵ�������Զ���ұߵ�����С��Ϊ�˷������������ǳ���ߵ�С��Ϊp���ұߵĴ���Ϊq�����Է��֣��������һ�θı䣬��ô�����Ĳ�ֵ������max(q, k-p)�����е�һ���ǵ����ı�p������ֵ���ڶ������ǵ����ı�q�����ֵ����mx = max(q, k-p)��x = q-p
        // ���Ƿ��֣������һ������Ĳ�ֵλ��[0,x)��(x,mx]�ڣ���ô�������ֻ��Ҫ�ı�һ�Σ������ڲ�ֵ����mx�����飬����Ҫ�������θı䣬�����ò������ֱ�Ӽ���
        // ��Ϊ�ڲ�������У���Ҫ��[a,b)�ڵ�������������1��ֻ��Ҫ�Բ�������a��1������b��1���ɣ�������dp[i]�����������ԵĲ�ֵ�ı�Ϊi����С������ͬʱ����d���������飬��ô���Ҫ��dp[0...x-1]��1����dp[x+1...mx]��1��ͬʱ��dp[mx...k]����2��ֻ��Ҫ�������²�����d[0]++,d[x]--,d[x+1]++,d[mx+1]--,d[mx+1]+=2����
        // ���ջ�ԭ����dp������С��������
        int n = nums.size();
        vector<int> d(k+2);
        for (int i=0; i<n/2; i++){
            int p = nums[i], q = nums[n-i-1];
            if (p > q){
                swap(p, q);
            }
            int x = q-p;
            int mx = max(q, k-p);
            d[0]++;
            d[x]--;
            d[x+1]++;
            d[mx+1]--;
            d[mx+1] += 2;
        }
        // for (int i=1; i<=k+1; i++){
        //     d[i] += d[i-1];
        // }
        partial_sum(d.begin(), d.end(), d.begin());
        return *min_element(d.begin(), d.end());
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,6,7,8}, moveFrom = {1,7,2}, moveTo = {2,9,5};
    vector<int> res = s.relocateMarbles(nums, moveFrom, moveTo);
    for (auto i : res) cout << i << " ";
    cout << endl;
    nums = {1,0,1,2,4,3};
    int k = 4;
    cout << s.minChanges(nums, k) << endl;
}
