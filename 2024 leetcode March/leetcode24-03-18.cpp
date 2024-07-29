#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> sum_num;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        sum_num.push_back(0);
        for (int &i : nums){
            sum += i;
            sum_num.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return sum_num[right+1]-sum_num[left];
    }
};

int main(){
    vector<int> nums = {-2,0,3,-5,2,-1};
    vector<vector<int>> sums = {{0,2},{2,5},{0,5}};
    NumArray* obj = new NumArray(nums);
    for (auto &i : sums){
        int left = i[0], right = i[1];
        int param = obj->sumRange(left,right);
        cout << param << " ";
    }
    return 0;
}
