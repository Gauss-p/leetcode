#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumRobots(vector<int>& T, vector<int>& C, long long budget) {
        // 根据题目可以知道，总开销只和所选的机器人的充电最大时间以及它们的运行总开销有关，所以我们可以用华东窗口的思路，不定长滑窗。循环右端点，在循环外定义左端点，同时用一个单调队列记录所选机器人的所有充电时间，以及用一个sum记录运行时的开销总和
        // 每一次循环到一个新的机器人，我们就需要将其充电时间的索引加入单调队列中(防止充电时间的数值重复)，我们保证单调队列的最左边是最大值，最右边是最小值，所以加入的索引需要从右边开始进行比较，只要当前索引对应的充电时间比已记录的最小充电时间大，就将最小充电时间弹出，不断计算并弹出，直到当前充电时间可以作为整个队列的最小值时才加入
        // 同时加入运行总开销，为了防止超出budget，我们需要检测当前情况并右移左端点，对于总运行开销，只需要减去即可，而对于充电时间，则需要比较，如果之前记录的最大充电时间和左端点对应的充电时间相等，就将队列中的最大充电时间弹出即可
        // 一直到最后，记录最大机器人数量
        vector<long long> q;
        int n = T.size();
        int l = 0;
        long long sum = 0;
        int res = 0;
        for (int r=0; r<n; r++){
            while (q.size() && T[q.back()] < T[r]){
                q.pop_back();
            }
            q.push_back(r);
            sum += C[r];
            // 以上是压入第r个机器人的数据
            while (l<=r && 1ll*T[q[0]]+1ll*(r-l+1)*sum > budget){
                if (l == q[0]){
                    q.erase(q.begin());
                }
                sum -= C[l];
                // 弹出第l个机器人的数据
                l++;
            }
            res = max(res, r-l+1); // 记录答案
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> T = {3,6,1,3,4};
    vector<int> C = {2,1,3,4,5};
    long long budget = 25;
    cout << s.maximumRobots(T,C,budget) << endl;
}
