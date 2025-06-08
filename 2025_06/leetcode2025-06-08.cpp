#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> res;
    int N;

    void dfs(int cur, int is_beg){
        res.push_back(cur);
        for (int i=is_beg; i<=9; i++){
            if (cur*10+i <= N){
                dfs(cur*10+i, is_beg&0);
            }
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        N = n;
        dfs(0, 1);
        res.erase(res.begin());
        return res;
    }
};

int main(){
    Solution s;
    int n = 13;
    vector<int> res = s.lexicalOrder(n);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
