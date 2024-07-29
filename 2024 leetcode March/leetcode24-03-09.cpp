#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long sum = 0L;
        for (int &i : nums){
            if (i >= 0){
                sum += i;
            }
            else{
                i = -i;
            }
        }
        sort(nums.begin(), nums.end());
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> q;
        q.emplace(0, 0);
        while (--k){
            auto [s, i] = q.top();
            q.pop();
            int tmp_size = nums.size();
            if (i < tmp_size){
                q.emplace(s+nums[i], i+1);
                if (i){
                    q.emplace(s+nums[i]-nums[i-1], i+1);
                }
            }
        }
        return sum-q.top().first;
    }
};

int main(int argc, char **argv){
	Solution s;
	vector<int> nums = {1,-2,3,4,-10,12};
	int k = 16;
	cout << s.kSum(nums, k) << endl;
	return 0;
}
