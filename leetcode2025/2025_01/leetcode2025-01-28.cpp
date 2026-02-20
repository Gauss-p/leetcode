#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> dfs(int x){
        if (x==0) return {1};
        if (x==1) return {1,1};
        vector<int> tmp = dfs(x-1);
        vector<int> res = {1};
        for (int i=1; i<tmp.size(); i++){
            res.push_back(tmp[i-1]+tmp[i]);
        }
        res.push_back(1);
        return res;
    }
public:
    vector<int> getRow(int rowIndex) {
        return dfs(rowIndex);
    }
};

int main(){
    Solution s;
    int rowIndex = 10;
    vector<int> res = s.getRow(rowIndex);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
