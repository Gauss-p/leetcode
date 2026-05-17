#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int n;
    vector<int> visited, Arr;
    
    bool dfs(int indx){
        if (indx < 0 || indx >= n || visited[indx]){
            return false;
        }
        if (Arr[indx] == 0){
            return true;
        }
        visited[indx] = 1;
        return dfs(indx+Arr[indx]) | dfs(indx-Arr[indx]);
    }

public:
    bool canReach(vector<int>& arr, int start) {
        Arr = arr;
        n = arr.size();
        visited.resize(n, 0);
        return dfs(start);
    }
};

int main(){
    Solution s;
    vector<int> arr = {4,2,3,0,3,1,2};
    int start = 5;
    cout << s.canReach(arr, start) << endl;
}
