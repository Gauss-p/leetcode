#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int reversedPairs = 0;
        set<pair<long long, int>> stPairs;
        set<int> stIndx;
        vector<long long> newNums(nums.begin(), nums.end());

        for (int i=0; i<n-1; i++){
            stPairs.emplace(1ll*(newNums[i]+newNums[i+1]), i);
            stIndx.insert(i);
            if (newNums[i] > newNums[i+1]){
                reversedPairs++;
            }
        }
        stIndx.insert(n-1);

        int res = 0;
        while (reversedPairs){
            res++;
            pair<long long, int> top = *stPairs.begin();
            long long s = top.first;
            int i = top.second;
            stPairs.erase(stPairs.begin());

            auto jpos = stIndx.upper_bound(i);
            int j = *jpos;

            if (newNums[i] > newNums[j]){
                reversedPairs--;
            }
            
            auto ipos = prev(jpos);
            if (ipos != stIndx.begin()){
                auto apos = prev(ipos);
                int a = *apos;
                if (newNums[a] > newNums[i]){
                    reversedPairs--;
                }
                if (newNums[a] > s){
                    reversedPairs++;
                }
                stPairs.erase(make_pair(newNums[a]+newNums[i], a));
                stPairs.emplace(newNums[a]+s, a);
            }

            auto kpos = next(jpos);
            if (kpos != stIndx.end()){
                int k = *kpos;
                if (newNums[j] > newNums[k]){
                    reversedPairs--;
                }
                if (s > newNums[k]){
                    reversedPairs++;
                }
                stPairs.erase(make_pair(newNums[j]+newNums[k], j));
                stPairs.emplace(s+newNums[k], i);
            }

            newNums[i] = s;
            stIndx.erase(j);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,2,3,1};
    cout << s.minimumPairRemoval(nums) << endl;
}
