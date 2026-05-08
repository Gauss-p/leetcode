#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int maxNum = 1000001;
vector<vector<int>> factors(maxNum);
int init = []{
    for (int i=2; i<maxNum; i++){
        if (factors[i].size()){
            continue;
        }
        for (int j=i; j<maxNum; j+=i){
            factors[j].push_back(i);
        }
    }
    return 0;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> g;
        for (int i=0; i<n; i++){
            for (int p : factors[nums[i]]){
                g[p].push_back(i);
            }
        }

        vector<int> q = {0};
        vector<int> visited(n, 0);
        int res = 0;
        while (q.size()){
            vector<int> newQ;
            for (int i : q){
                if (visited[i]){
                    continue;
                }
                if (i == n-1){
                    return res;
                }
                visited[i] = 1;
                newQ.push_back(i+1);
                if (i > 0){
                    newQ.push_back(i-1);
                }
                for (int nxt : g[nums[i]]){
                    newQ.push_back(nxt);
                }
                g[nums[i]] = {};
            }
            q = newQ;
            res++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,4,6};
    cout << s.minJumps(nums) << endl;
}
