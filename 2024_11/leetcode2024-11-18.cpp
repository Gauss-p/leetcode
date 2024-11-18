#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int m, n;
    int calAverage(vector<vector<int>>& img, int x, int y){
        vector<vector<int>> dir = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};// 八个方向
        int cnt = 1, totalSum = img[x][y];
        for (auto& d : dir){
            int nx = x+d[0], ny = y+d[1];
            if (nx>=0 && nx<m && ny>=0 && ny<n){
                cnt++;
                totalSum += img[nx][ny];
            }
        }
        return totalSum/cnt;
    }
    vector<vector<int>> sim(vector<vector<int>>& img){
        // 直接模拟
        vector<vector<int>> newImg(m, vector<int>(n, 0));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                newImg[i][j] = calAverage(img, i, j);
            }
        }
        return newImg;
    }
    vector<vector<int>> preSum(vector<vector<int>>& img){
        vector<vector<int>> pre(m+1, vector<int>(n+1));
        // 计算前缀和
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                pre[i][j] = pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]+img[i-1][j-1];
            }
        }
        vector<vector<int>> res(m, vector<int>(n));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int a = max(i-1, 0), b = max(j-1, 0);
                int c = min(i+1, m-1), d = min(j+1, n-1);
                int cnt = (c-a+1)*(d-b+1);
                // 直接用前缀和求范围[(a,b),(c,d)]内的矩形元素和即可
                int totalSum = pre[c+1][d+1]-pre[a][d+1]-pre[c+1][b]+pre[a][b];
                res[i][j] = totalSum/cnt;
            }
        }
        return res;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        m = img.size();
        n = img[0].size();
        // return sim(img);
        return preSum(img);
    }
};

int main(){
    Solution s;
    vector<vector<int>> img = {{100,200,100},{200,50,200},{100,200,100}};
    vector<vector<int>> res = s.imageSmoother(img);
    for (auto&i : res){
        for (auto&j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
