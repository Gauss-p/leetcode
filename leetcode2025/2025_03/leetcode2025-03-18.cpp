#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool isPrime(int x){
        if (x==1) return false;
        for (int i=2; i*i<=x; i++){
            if (x%i == 0){
                return false;
            }
        }
        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i=0; i<n; i++){
            if (isPrime(nums[i][i])){
                res = max(res, nums[i][i]);
            }
            if (isPrime(nums[i][n-i-1])){
                res = max(res, nums[i][n-i-1]);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> nums = {{1,2,3},{5,6,7},{9,10,11}};
    cout << s.diagonalPrime(nums) << endl;
}
