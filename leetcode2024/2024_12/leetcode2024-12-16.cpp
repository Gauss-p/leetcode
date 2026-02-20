#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <ranges>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        // 为了方便计算，我们可以将queries按照每个查询中的最小面积从大到小排序，但是又因为题目要求我们按顺序返回答案，所以我们需要将queries的每个元素和它自身的索引一起排序。定义queries的大小为q，我们可以使用一个技巧，即单独排序[0,q]的所有元素，但是排序函数我们定义为lambda i:-queries[i][1]，这样我们就可以将所有序号按照它们对应的查询的第二个值——minSize按照从大到小的顺序排序，其中负号的作用就是反向排序
        // 同时，我们将rooms数组按照房间大小从小到大的顺序进行排序
        // 然后创建一个有序集合 roomId。用双指针遍历 query_id 和 rooms，把房间面积 ≥minSize 的房间号添加到 roomId 中。然后在 roomId 中搜索离 pre 最近的左右两个房间号，其中离 pre 最近的房间号就是答案。
        // sort(rooms.begin(), rooms.end(), [](auto& a, auto& b){return a[1]<b[1];});
        sort(rooms.begin(), rooms.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int q = queries.size();
        vector<int> query_id(q);
        iota(query_id.begin(), query_id.end(), 0);
        // sort(query_id.begin(), query_id.end(), [](int a, int b){return -queries[a][1]<-queries[b][1];});
        sort(query_id.begin(), query_id.end(), [&](int i, int j) {
            return queries[i][1] > queries[j][1];
        });

        vector<int> res(q, -1);
        int j = rooms.size()-1;
        set<int> roomId;
        for (int i : query_id){
            int per = queries[i][0], minSize = queries[i][1];
            while (j>=0 && rooms[j][1]>=minSize){
                // 把房间面积 ≥minSize 的房间号加入roomId中
                roomId.insert(rooms[j][0]);
                j--;
            }

            auto it = roomId.lower_bound(per);
            int diff = INT_MAX;
            if (it != roomId.begin()){ // 左边
                auto k = prev(it);
                diff = per-*k;
                res[i] = *k;
            }
            if (it != roomId.end() && *it-per < diff){ // 右边
                res[i] = *it;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> rooms = {{2,2},{1,2},{3,2}};
    vector<vector<int>> queries = {{3,1},{3,3},{5,2}};
    vector<int> res = s.closestRoom(rooms, queries);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
