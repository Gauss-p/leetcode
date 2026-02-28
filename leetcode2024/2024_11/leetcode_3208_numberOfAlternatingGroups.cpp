#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int cnt = 1;
        int res = 0;
        // cnt用来记录colors中交替子序列的长度，也就是，如果发现colors[i]!=colors[i-1]就将cnt加1，否则将cnt重置为1，那么在这种情况下，我们只要发现cnt>=k，就要统计一次答案，因为当cnt>=k时就说明colors中已经出现了一个长度至少为k的交替子序列。那么为什么我们不需要每次都加上cnt-k+1呢？因为如果只用加1进行统计的话，在每次加之前，前面的所有长度为k的子序列都已经被加入答案了，这一次就不需要再考虑之前的了
        // 这里从-k+2的位置开始循环是因为题目中说瓷砖是循环的，那么我们如果首先从-k+2的位置开始比较，那么0位置恰好是第k-1个被比较的，再加上最开始的-k+1，就正好凑成一个长度为k的区间，这样就可以解决循环比较的问题
        for (int i=-k+2; i<n; i++){
            if (colors[(i+n)%n] != colors[(i-1+n)%n]){
                cnt++;
            }
            else{
                cnt = 1;
            }
            if (cnt >= k){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> colors = {0,1,0,1,0};
    int k = 3;
    cout << s.numberOfAlternatingGroups(colors, k) << endl;
}
