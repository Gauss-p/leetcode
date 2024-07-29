#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution1 {
public:
    string findLatestTime(string s) {
        for (int i=0; i<5; i++){
            auto &c = s[i];
            if (c == '?'){
                if (i == 0){
                    if (s[1] != '?' && s[1] > '1'){
                        c = '0';
                    }
                    else{
                        c = '1';
                    }
                }
                if (i == 1){
                    if (s[0] == '0') c = '9';
                    else c = '1';
                }
                if (i == 3) c = '5';
                if (i == 4) c = '9';
            }
        }
        return s;
    }
};

class Solution2 {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        unordered_set<int> primes;
        for (int i=2; i<101; i++){
            bool flag = true;
            for (int j=2; j<i; j++){
                if (i % j == 0){
                    flag = false;
                    break;
                }
            }
            if (flag) primes.insert(i);
        }
        int n = nums.size();
        int begin = 0, end = 0;
        for (int i=0; i<n; i++){
            if (primes.count(nums[i])){
                begin = i;
                break;
            }
        }
        for (int i=n-1; i>=0; i--){
            if (primes.count(nums[i])){
                end = i;
                break;
            }
        }
        return end-begin;
    }
};

int main(){
    Solution1 s1;
    string s = "?3:5?";
    cout << s1.findLatestTime(s) << endl;
    // -----------------------------------------------------------------
    Solution2 s2;
    vector<int> nums = {4,2,9,5,3};
    cout << s2.maximumPrimeDifference(nums) << endl;
}
