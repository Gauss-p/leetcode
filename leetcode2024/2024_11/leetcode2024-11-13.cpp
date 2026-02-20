#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        // 为了解决这个问题，我们可以存储一个数组left，长度和s的长度n一样，每一个元素left[i]表示：以i为右端点，在保证子字符串满足k约束的情况下左端点最小是多少。也就是说我们可以保证子数组s[left[i], i]满足k约束并且总长度最大
        // 那么对于每一个查询[l,r]，可以分成以下两种情况：
        // 1.left[r]<=l    也就是说，我们待查询的区间正好是一个满足k约束的区间，所以最终的答案很简单，就是(r-l+2)*(r-l+1)/2，即[l,r]中所有的连续子字符串数量
        // 2.left[r]>l    也就是说，当前区间并不是一个完整的满足k约束的区间，这个时候我们可以将整个区间分成两段进行考虑，其分界点为j。j满足以下条件:j最小，并且left[j]>=l。这个时候我们可以知道，区间[l,j-1]一定是一个满足k约束的区间，那么其中的满足k约束的子字符串数量就是(j-l+1)*(j-l)/2。而对于另外一半，区间[j,r]中，这可能不是一个完整的满足k约束的区间，所以我们在[j,r]中循环i，同时累加：以i为右端点的所有满足k约束的子字符串的数量，最终，将两者相加，即可计算出区间[l,r]中的满足k约束的子字符串总数
        // 但是我们发现还可以进行优化。对于第二种情况，我们可以直接利用前缀和的方式来计算区间[j,r]中所有满足k约束的子字符串的数量，定义一个前缀和数组preSum，长度为n+1，preSum[i]即为区间[0,i-1]中所有满足k约束的子字符串的数量，那么在计算[j,r]中的总数量时，就可以直接计算preSum[r+1]-preSum[j]，所以第二种情况下的答案就是(preSum[r+1]-preSum[j])+((j-l+1)*(j-l)/2)
        // 为了简化代码，我们可以将两种情况合并。我们发现，在第一种情况下，如果要查找一个j，那么查找出来的j一定是r+1，所以这时(r-l+2)*(r-l+1)/2就变成了(j-l+1)*(j-l)/2，同时，preSum[r+1]-preSum[j]就变成了0，所以，无论是哪种情况，我们都可以使用(preSum[r+1]-preSum[j])+((j-l+1)*(j-l)/2)来计算答案
        int n = s.size();
        vector<int> left(n); // 每一个右端点对应的最小左端点
        vector<long long> preSum(n+1, 0); // 前缀和
        int l = 0;
        int cnt0 = 0, cnt1 = 0;
        for (int r=0; r<n; r++){
            // 不定长滑动窗口
            cnt0 += (s[r] == '0');
            cnt1 += (s[r] == '1');
            while (cnt0 > k && cnt1 > k){
                cnt0 -= (s[l] == '0');
                cnt1 -= (s[l] == '1');
                l++;
            }
            left[r] = l;
            preSum[r+1] = preSum[r]+(r-l+1); // 计算[0,r]内所有满足k约束子字符串的总量
        }

        vector<long long> res;
        for (auto& q : queries){
            int l = q[0], r = q[1];
            int j = lower_bound(left.begin()+l, left.begin()+r+1, l)-left.begin(); // 查找分界点j
            res.push_back(preSum[r+1]-preSum[j]+1ll*(j-l+1)*(j-l)/2); // 计算答案
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "010101";
    int k = 1;
    vector<vector<int>> queries = {{0,5},{1,4},{2,3}};
    vector<long long> res = sl.countKConstraintSubstrings(s, k, queries);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
