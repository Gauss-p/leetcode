#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

class UFS{
private:
    vector<int> pa;
public:
    UFS(int n){
        for (int i=0; i<n; i++){
            pa.push_back(i);
        }
    }

    int find(int x){
        if (pa[x] != x){
            pa[x] = find(pa[x]);
        }
        return pa[x];
    }

    void merge(int x, int y){
        int px = find(x), py = find(y);
        if (px<py){
            pa[py] = px;
        }
        else{
            pa[px] = py;
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        UFS ufs(n);
        for (auto& r : roads){
            int a=r[0]-1, b=r[1]-1, d=r[2];
            ufs.merge(a, b);
        }

        int target = ufs.find(0);
        unordered_set<int> st;
        for (int i=0; i<n; i++){
            if (ufs.find(i) == target){
                st.insert(i);
            }
        }

        int res = INT_MAX;
        for (auto& r : roads){
            int a=r[0]-1, b=r[1]-1, d=r[2];
            if (st.count(a) && st.count(b)){
                res = min(res, d);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 4;
    vector<vector<int>> roads = {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
    cout << s.minScore(n, roads) << endl;
}
