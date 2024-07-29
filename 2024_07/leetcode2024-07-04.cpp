#include <iostream>
#include <climits>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        // 思路是这样的，我们可以分两种情况，第一种是可以直接用改变相邻值再交换，最终达成目标
        // 第二种是就算将所有的改变次数都用玩都没办法达成目标
        // 首先考虑第一种,因为要让相邻位置和自己所处位置的金币最多,所以最好是站在三个连续1的中间
        // 如果没有三个连续的1,就找两个,否则就找1个,我们用c来存储nums中最大连续1的数目
        // 可以发现，如果有三个连续1，我们可以花费两步拿到三个，如果有两个就花费一步拿到两个，否则不花步数拿1个
        // 在取完所站地点周围的金币后，我们可以通过在旁边生成一个1，再把新的1交换到当前位置并拾取的方法拿到maxChanges个金币，因为是第一种情况，也就是用完所有改变的机会后可以取到k个金币，所以推出，第一种情况的步数就是：max(0, c-1)+(k-c)*2，并且我们需要保证maxChanges >= k-c
        // 再来看第二种情况，这个时候就算用完maxChanges，也没办法达到k个金币
        // 这是我们就需要考虑其他地方的金币了,我们知道,还需要找到k-maxChanges个金币才能达成目标
        // 为了方便说明,我们称moveSize = k-maxChanges
        // 首先保存所有1的位置,接下来我们要找一个位置,使得这个位置到周围moveSize个1的距离之和最小,可以知道,这个位置就是k个1的位置的中位数
        // 所以,我们只需要在存储1的位置的向量pos中遍历即可,每一次都找k个1的位置,再取其中的中位数进行计算即可
        // 为了方便计算，我们可以推导一下已知一组数据的中位数，如何求中位数到其他所有元素距离之和
        // 因为这个地方所说的数组其实已经按照从小到大的顺序排序，所以我们称小于其中位数的数为中位数左边的数，大于其中位数的数为中位数右边的数
        // 我们要求的，是中位数到所有数的差的绝对值的和，所以对于左边的数，我们可以用左边的数的个数乘以中位数再减去所有左边的数的和，对于右边的数，我们可以用右边的数的个数乘以中位数再减去所有右边的数的和
        // 也就是分段求和，最后相加即可
        // 而左右两边的数字之和，可以用前缀和来计算
        // 注意,现在我们只计算出了需要通过一步一步移动的1最少需要多少步,所以最后我们还需要利用maxChanges生成maxChanges个1,这需要maxChanges*2步
        // 所以,情况二一共需要:将moveSize个1移动到一个位置的最小步数,加上maxChanges*2即可
        vector<int> pos;
        int c = 0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            if (nums[i] == 0) continue;
            pos.push_back(i);
            c = max(c, 1);
            if (i > 0 && nums[i-1] == 1){
                if (i > 1 && nums[i-2] == 1){
                    c = 3;
                }
                else{
                    c = max(c, 2);
                }
            }
        }
        c = min(c, k);
        if (maxChanges >= k-c){
            return max(0, c-1)+2*(k-c);
        }

        int len_pos = pos.size();
        int moveSize = k-maxChanges;
        long long res = LLONG_MAX;
        vector<long long> prev_sum(n+1, 0);
        for (int i=0; i<len_pos; i++){
            prev_sum[i+1] = prev_sum[i]+pos[i];
        }

        for (int r=moveSize; r<len_pos+1; r++){
            int l = r-moveSize;
            int mid = l+moveSize/2;
            long long s1 = 1ll*pos[mid]*(mid-l)-1ll*(prev_sum[mid]-prev_sum[l]);
            long long s2 = 1ll*(prev_sum[r]-prev_sum[mid])-1ll*pos[mid]*(r-mid);
            res = min(res, s1+s2);
            // cout << s1 << " " << s2 << endl;
        }
        return res+2*maxChanges;
    }
};

int main(){
    bitset<16> bs(1);
    cout << bs.to_string() << endl;
    string cur = bs.to_string();
    cur = cur.substr(cur.size()-1, 1);
    cout << cur << endl;
    // Solution s;
    // vector<int> nums = {1,1,0,0,0,1,1,0,0,1};
    // int k = 3, maxChanges = 1;
    // cout << s.minimumMoves(nums, k, maxChanges) << endl;
}
