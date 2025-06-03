#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> hasKey, hasBox, Candies;
    vector<vector<int>> Keys, ContainedBoxes;
    int res;

    void dfs(int x){
        res += Candies[x];
        hasBox[x] = 0;

        for (int y : Keys[x]){
            hasKey[y] = 1;
            if (hasBox[y]){
                dfs(y);
            }
        }

        for (int y : ContainedBoxes[x]){
            hasBox[y] = 1;
            if (hasKey[y]){
                dfs(y);
            }
        }
    }

public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        hasKey = status;
        hasBox.resize(n, 0);
        for (int i : initialBoxes){
            hasBox[i] = 1;
        }
        res = 0;
        Candies = candies;
        Keys = keys;
        ContainedBoxes = containedBoxes;

        for (int i : initialBoxes){
            if (hasBox[i] && hasKey[i]){
                dfs(i);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> status = {1,0,1,0}, candies = {7,5,4,100}, initialBoxes = {0};
    vector<vector<int>> keys = {{},{},{1},{}}, containedBoxes = {{1,2},{3},{},{}};
    cout << s.maxCandies(status, candies, keys, containedBoxes, initialBoxes) << endl;
}
