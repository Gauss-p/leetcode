#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class UFS{
private:
    vector<int> pa;
public:
    int cnt;
    UFS(int n){
        for (int i=0; i<n; i++){
            pa.push_back(i);
        }
        cnt = n;
    }

    int find(int x){
        if (pa[x] != x){
            pa[x] = find(pa[x]);
        }
        return pa[x];
    }

    void merge(int x, int y){
        int px = find(x), py = find(y);
        if (px != py){
            pa[max(px, py)] = min(px, py);
            cnt--;
        }
    }
};

class Solution {
private:
    int calc(int x){
        int ans = 0;
        while (x){
            ans += x%10;
            x /= 10;
        }
        return ans;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums = nums;
        sort(newNums.begin(), newNums.end(), [&](auto&a, auto&b){
            return calc(a)<calc(b) || (calc(a)==calc(b) && a<b);
        });
        unordered_map<int, int> pos;
        for (int i=0; i<n; i++){
            pos[nums[i]] = i;
        }

        UFS ufs(n);
        for (int i=0; i<n; i++){
            int p1 = pos[newNums[i]], p2 = i;
            ufs.merge(p1, p2);
        }
        return n-ufs.cnt;
    }
};

int main(){
    Solution s;
    vector<int> nums = {37,100};
    cout << s.minSwaps(nums) << endl;
}
