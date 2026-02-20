#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int res = 0;
        unordered_set<int> st;
        for (auto i : points){
            st.insert(i[0]);
        }
        vector<int> x(st.begin(), st.end());
        sort(x.begin(), x.end());
        int begin = x[0];
        for (int i=1; i<x.size(); i++){
            if (x[i] > begin+w){
                res++;
                begin = x[i];
            }
        }
        res++;
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> points = {{2,1},{1,0},{1,4},{1,8},{3,5},{4,6}};
    int w = 1;
    cout << s.minRectanglesToCoverPoints(points, w) << endl;
}
