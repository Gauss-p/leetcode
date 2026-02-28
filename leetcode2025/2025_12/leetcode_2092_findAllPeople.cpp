#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UFS{
public:
    vector<int> pa;
    UFS(int n){
        pa.resize(n);
        for (int i=0; i<n; i++){
            pa[i] = i;
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
        pa[px] = py;
    }

    bool isSame(int x, int y){
        return find(x)==find(y);
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b){
            return a[2] < b[2];
        });
        UFS ufs(n);
        ufs.merge(0, firstPerson);
        int m = meetings.size();
        int i = 0;
        while (i<m){
            int start = i;
            int time = meetings[i][2];
            while (i < m && meetings[i][2] == time){
                ufs.merge(meetings[i][0], meetings[i][1]);
                i++;
            }

            for (int j=start; j<i; j++){
                int x = meetings[j][0], y = meetings[j][1];
                if (!ufs.isSame(x, 0)){
                    ufs.pa[x] = x;
                }
                if (!ufs.isSame(y, 0)){
                    ufs.pa[y] = y;
                }
            }
        }

        vector<int> res;
        for (int i=0; i<n; i++){
            if (ufs.isSame(i, 0)){
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 6;
    vector<vector<int>> meetings = {{1,2,5},{2,3,8},{1,5,10}};
    int firstPerson = 1;
    vector<int> res = s.findAllPeople(n, meetings, firstPerson);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
