#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int quick_pow2(int b, int m){
        long long a = 2;
        int res = 1;
        while (b){
            if (b&1){
                res = (res*a)%m;
            }
            b >>= 1;
            a = (a*a)%m;
        }
        return res;
    }
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> nums;
        while (n){
            nums.push_back(32-__builtin_clz(n&(-n))-1);
            n ^= (n&(-n));
        }

        vector<long long> preProduct(nums.size()+1, 1);
        for (int i=0; i<nums.size(); i++){
            preProduct[i+1] = preProduct[i]+nums[i];
        }

        int modNum = 1e9+7;
        vector<int> res;
        for (auto& q : queries){
            int l = q[0], r = q[1];
            res.push_back(quick_pow2(preProduct[r+1]-preProduct[l], modNum));
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 15;
    vector<vector<int>> queries = {{0,1},{2,2},{0,3}};
    vector<int> res = s.productQueries(n, queries);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
