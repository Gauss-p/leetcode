#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> pos;
        for (int i=0; i<n; i++){
            pos[arr[i]].push_back(i);
        }

        vector<int> q = {0};
        int res = 0;
        vector<int> visited(n, 0);
        visited[0] = 1;
        while (!q.empty()){
            vector<int> q2;
            for (int x : q){
                if (x == n-1){
                    return res;
                }
                if (x > 0 && visited[x-1] == 0){
                    visited[x-1] = 1;
                    q2.push_back(x-1);
                }
                if (x < n-1 && visited[x+1] == 0){
                    visited[x+1] = 1;
                    q2.push_back(x+1);
                }
                for (int y : pos[arr[x]]){
                    if (visited[y]){
                        continue;
                    }
                    visited[y] = 1;
                    q2.push_back(y);
                }
                pos[arr[x]] = {};
            }
            q = move(q2);
            res++;
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    cout << s.minJumps(arr) << endl;
}
