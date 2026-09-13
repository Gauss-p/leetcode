#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> pos1;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (img1[i][j]){
                    pos1.emplace_back(i, j);
                }
            }
        }
        int res = 0;
        for (int i=-n+1; i<n; i++){
            for (int j=-n+1; j<n; j++){
                int cur = 0;
                for (auto& p : pos1){
                    int nx = i+p.first, ny = j+p.second;
                    if (nx<0 || nx>=n || ny<0 || ny>=n){
                        continue;
                    }
                    cur += img2[nx][ny];
                }
                res = max(res, cur);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> img1 = {{1,1,0},{0,1,0},{0,1,0}}, img2 = {{0,0,0},{0,1,1},{0,0,1}};
    cout << s.largestOverlap(img1, img2) << endl;
}
