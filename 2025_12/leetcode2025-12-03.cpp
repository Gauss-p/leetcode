#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<float, unordered_map<float, int>> kb_map;
        unordered_map<int, unordered_map<float, int>> mk_map;
        for (int i=0; i<n; i++){
            int x1 = points[i][0], y1 = points[i][1];
            for (int j=i+1; j<n; j++){
                int x2 = points[j][0], y2 = points[j][1];
                float dx = x2-x1, dy = y2-y1;
                int midx = x1+x2, midy = y1+y2;
                float k = INT_MAX, b = x1;
                if (dx != 0){
                    k = dy / dx;
                    b = (y1*dx-x1*dy)/dx;
                }
                kb_map[k][b]++;
                int mk_Key = (midx+2000)<<16 | (midy+2000);
                mk_map[mk_Key][k]++;
            }
        }

        int res = 0;
        for (auto& kb : kb_map){
            int s = 0;
            for (auto& ib : kb.second){
                res += s*ib.second;
                s += ib.second;
            }
        }

        for (auto& mk : mk_map){
            int s = 0;
            for (auto& ik : mk.second){
                res -= s*ik.second;
                s += ik.second;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> points = {{-3,2},{3,0},{2,3},{3,2},{2,-3}};
    cout << s.countTrapezoids(points) << endl;
}
