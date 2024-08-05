#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        // 以每一个元素作为正方形的一个顶点，计算此时正方形的半边长，将所有的半边长从小到大排序，再遍历一遍，什么时候有一个标签出现了两次，就再往回找，直到找到第一个不同于当前半边长的节点，返回答案即可
        // 如果没有任何一个标签出现了两次，就直接返回答案即可
        vector<pair<int, int>> vp;
        int n = points.size();
        for (int i=0; i<n; i++){
            vp.emplace_back(max(abs(points[i][0]), abs(points[i][1])), s[i]-'a');
        }
        sort(vp.begin(), vp.end());
        unordered_set<int> st;
        int res = 0;
        for (int i=0; i<vp.size(); i++){
            if (st.count(vp[i].second) == 0){
                res++;
                st.insert(vp[i].second);
            }
            else{
                for (int j=i-1; j>=0; j--){
                    if (vp[j].first == vp[i].first){
                        res--;
                    }
                }
                return res;
            }
        }
        return res;
    }
};

int main(){
    Solution so;
    vector<vector<int>> points = {{2,2},{-1,-2},{-4,4},{-3,1},{3,-3}};
    string s = "abdca";
    cout << so.maxPointsInsideSquare(points,s) << endl;
    cout << so.maxPointsInsideSquare(points, s) << endl;
}
