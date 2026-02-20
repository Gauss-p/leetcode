#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // 因为题目保证给出的数据中没有两条路会交叉，所以可以直接用贪心的方法解决，首先定义road，其中road[i]表示城市i通过一条有向路可以到达哪个城市，因此最开始road[i]都为i+1(在之后的运算中，road[i]如果为-1，就说明它已经被包含在某一条道路中间了，我们可以忽略以它开头的所有道路)，接下来循环queries，对于每一个新道路[u,v]，如果它已经被另一条道路包含在内，如[2,3]在[1,5]之内，我们就可以直接忽略它，否则，我们就可以选择当前道路，但是要注意，在选择它的时候，要将被它包含在内的所有道路去除，即对于这条路内的每一个城市x，都将road[x]置为-1，在置-1的过程中，我们可以只将每一条道路的起点置为-1即可，因为如果之前有加入道路的话，这条道路内所有点都已经被置为-1，就不需要再考虑它们了。
        vector<int> road(n);
        for (int i=0; i<n; i++){
            // 初始化
            road[i] = i+1;
        }
        vector<int> res;
        int dist = n-1; // 定义初始最短距离
        for (auto& q : queries){
            int k = road[q[0]];
            // 这里从起点的下一个点开始，是因为如果将起点置为-1，之后就算遇到更好的道路也没办法继续选择
            road[q[0]] = q[1]; // 直接添加道路
            while (k != -1 && k < q[1]){
                // 将道路中间的所有城市都置为-1
                int next = road[k];
                road[k] = -1;
                k = next;
                dist--; // 因为去掉了一条路，就将总距离减1
            }
            res.push_back(dist);
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 5;
    vector<vector<int>> queries = {{2,4},{0,2},{0,4}};
    vector<int> res = s.shortestDistanceAfterQueries(n, queries);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
