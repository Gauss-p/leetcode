#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
private:
    long long curSum;
    unordered_map<int, int> cnt;
    set<pair<int, int>> lstMax, lstRest;

    void add(int v){
        if (cnt[v] == 0){
            return;
        }
        pair<int, int> p = make_pair(cnt[v], v);
        if (!lstMax.empty() && p > *lstMax.begin()){
            lstMax.insert(p);
            curSum += 1ll*cnt[v]*v;
        }
        else{
            lstRest.insert(p);
        }
    }

    void remove(int v){
        if (cnt[v] == 0){
            return;
        }
        pair<int, int> p = make_pair(cnt[v], v);
        if (lstMax.count(p)){
            lstMax.erase(p);
            curSum -= 1ll*cnt[v]*v;
        }
        else{
            lstRest.erase(p);
        }
    }

public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        curSum = 0;
        int n = nums.size();
        vector<long long> res(n-k+1, 0);
        for (int i=0; i<n; i++){
            int v = nums[i];
            remove(v);
            cnt[v]++;
            add(v);

            int j = i-k+1;
            if (j < 0){
                continue;
            }

            while (!lstRest.empty() && (int)lstMax.size() < x){
                pair<int, int> p = *lstRest.rbegin();
                lstRest.erase(p);
                lstMax.insert(p);
                curSum += 1ll*p.first*p.second;
            }

            while ((int)lstMax.size() > x){
                pair<int, int> p = *lstMax.begin();
                lstMax.erase(p);
                lstRest.insert(p);
                curSum -= 1ll*p.first*p.second;
            }

            res[j] = curSum;
            remove(nums[j]);
            cnt[nums[j]]--;
            add(nums[j]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,2,2,3,4,2,3};
    int k = 6, x = 2;
    vector<long long> res = s.findXSum(nums, k, x);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
