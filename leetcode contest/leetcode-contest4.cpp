#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution1 {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0, y = x;
        while (y > 0){
            sum += y%10;
            y = y/10;
        }
        if (x % sum == 0){
            return sum;
        }
        return -1;
    }
};

class Solution2 {
public:
    int maxBottlesDrunk(int numBottles, int e) {
        int total_drank = numBottles, empty = numBottles;
        while (empty > 0){
            if (empty >= e){
                total_drank++;
                empty = empty-e+1;
                e++;
            }
            else{
                break;
            }
        }
        return total_drank;
    }
};

class Solution3 {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int indx = 0;
        long long res = 0;
        while (indx < n){
            int length = 1;
            while (indx < n-1 && nums[indx] != nums[indx+1]){
                length++;
                indx++;
            }
            indx++;
            res += 1ll*(length+1)*length/2;
        }
        return res;
    }
};

int main(){
    Solution1 s1;
    int x = 18;
    cout << s1.sumOfTheDigitsOfHarshadNumber(x) << endl;
    // -----------------------------------------------------------------
    Solution2 s2;
    int numBottles = 13, numExchange = 6;
    cout << s2.maxBottlesDrunk(numBottles, numExchange) << endl;
    // -----------------------------------------------------------------
    Solution3 s3;
    vector<int> nums = {0,1,1,1};
    cout << s3.countAlternatingSubarrays(nums) << endl;
    
    // ====vector push_back resize test
    vector<int> a={1,2,3};
    for(auto & i: a){
        cout << i << endl;
    }
    a.resize(5);
    a.emplace_back(88);
    for(auto & i: a){
        cout << i << endl;
    }
}
