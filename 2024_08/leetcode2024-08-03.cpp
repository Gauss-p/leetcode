#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
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
    cout << so.maxPointsInsideSquare(points, s) << endl;
}
