#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        // 这道题的思路是这样的，如果有一对a, b，其中a=b，那么我们可以知道答案就是b，同时，如果a在b的左侧，并且a的高度比b的高度低，那么同样我们可以知道答案就是b，对于剩下的情况，用小根堆处理
        // 首先，对于每一个需要查询的右边的下标，我们存储了在这个下标左边的另外一个下标，当然我们也需要存储这是第几个问题，在最后方便回答，接下来，从头到尾循环下标i，如果之前有某一个下标可以跳到当前下标i，那么答案就是i，因为我可以保证i是最左边的一个答案，然后每回答完一个问题就将这个问题弹出不予考虑，就这样一直循环下去即可。要注意在每一次循环i的时候，要回答的问题必须是在i之前出现的。
        int n = queries.size();
        vector<vector<pair<int, int>>> qs(heights.size());
        vector<int> res(n, -1);
        for (int i=0; i<n; i++){
            auto q = queries[i];
            int a = q[0], b = q[1];
            if (a > b){
                swap(a, b);
            }
            if (a == b || heights[a] < heights[b]){
                res[i] = b;
            }
            else{
                qs[b].emplace_back(heights[a], i);
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i=0; i<heights.size(); i++){
            while (!pq.empty() && pq.top().first < heights[i]){
                res[pq.top().second] = i;
                pq.pop();
            }
            for (auto q : qs[i]){
                pq.push(q);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> heights = {6,4,8,5,2,7};
    vector<vector<int>> queries = {{0,1},{0,3},{2,4},{3,4},{2,2}};
    vector<int> res = s.leftmostBuildingQueries(heights, queries);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}
