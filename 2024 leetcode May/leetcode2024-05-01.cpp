#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        // heap里面存的是每一个元素的值以及它的索引
        int n = costs.size();
        int can_l = candidates-1, can_r = n-candidates;
        // l和r分别表示从左往右数第candidates个元素的索引和从右往左数第candidates个元素的索引
        if (can_l < can_r){
            // 如果左右两个部分没有重叠的，那么就分别加入，否则加入所有员工
            for (int i=0; i<=can_l; i++){
                heap.emplace(make_pair(costs[i], i));
            }
            for (int i=can_r; i<n; i++){
                heap.emplace(make_pair(costs[i], i));
            }
        }
        else{
            for (int i=0; i<n; i++){
                heap.emplace(make_pair(costs[i], i));
            }
        }
        // cout << can_l << " " << can_r << endl;
        long long res = 0;
        for (int i=0; i<k; i++){
            // 根据小根堆的特性可以知道，最顶端的pair存的一定是价钱最小同时索引最小的工人
            int c = heap.top().first, indx = heap.top().second;
            res += c;
            // cout << c << " " << indx << endl;
            heap.pop();
            if (can_l+1 < can_r){
                if (indx <= can_l){
                    // 如果此时选中的工人在左边部分，那么左边被剔除了一个就应该往后多加一个
                    // 同理,如果此时选中的工人在右边部分,那么右边被剔除了一个就应该往前多加一个
                    can_l++;
                    heap.emplace(make_pair(costs[can_l], can_l));
                }
                if (indx >= can_r){
                    can_r--;
                    heap.emplace(make_pair(costs[can_r], can_r));
                }
            }
        }
        return res;
        // set<int> removed;
        // long long res = 0;
        // int n = costs.size();
        // while (n > candidates && k > 0){
        //     int tmp = 0, indx = n-1, r_eras = 0, r_num = INT_MAX;
        //     while (tmp < candidates){
        //         if (removed.count(indx)){
        //             indx--;
        //             continue;
        //         }
        //         tmp++;
        //         if (costs[indx] < r_num){
        //             r_num = costs[indx];
        //             r_eras = indx;
        //         }
        //         indx--;
        //     }
        //     // cout << "r_num:" << r_num << " r_eras:" << r_eras << endl;
        //     tmp = 0;
        //     indx = 0;
        //     int l_eras = 0, l_num = INT_MAX;
        //     while (tmp < candidates){
        //         if (removed.count(indx)){
        //             indx++;
        //             continue;
        //         }
        //         tmp++;
        //         if (costs[indx] < l_num){
        //             l_num = costs[indx];
        //             l_eras = indx;
        //         }
        //         indx++;
        //     }
        //     if (l_num < r_num){
        //         removed.insert(l_eras);
        //         // cout << l_eras << endl;
        //     }
        //     if (r_num < l_num){
        //         removed.insert(r_eras);
        //         // cout << r_eras << endl;
        //     }
        //     if (l_num == r_num){
        //         removed.insert(min(l_eras, r_eras));
        //         // cout << min(l_eras, r_eras) << endl;
        //     }
        //     res += min(l_num, r_num);
        //     k--;
        //     n--;
        // }
        // if (k == 0) return res;
        // vector<int> new_cost;
        // for (int i=0; i<costs.size(); i++){
        //     if (removed.count(i) == 0){
        //         new_cost.push_back(costs[i]);
        //     }
        // }
        // sort(new_cost.begin(), new_cost.end());
        // // for (int i : new_cost) cout << i << " ";
        // for (int i=0; i<k; i++){
        //     res += new_cost[i];
        // }
        // return res;
    }
};

int main(){
    Solution s;
    vector<int> costs = {17,12,10,2,7,2,11,20,8};
    int k = 3, candidates = 4;
    cout << s.totalCost(costs, k, candidates) << endl;
}
