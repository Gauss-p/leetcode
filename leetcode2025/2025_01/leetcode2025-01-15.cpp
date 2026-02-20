#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int res = 0;
        while (pq.size()>=2 && pq.top()<k){
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(x*2+y);
            res++;
        }
        return pq.top()<k ? -1 : res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,11,10,1,3};
    int k = 10;
    cout << s.minOperations(nums, k) << endl;
}
