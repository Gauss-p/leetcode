#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int max_num = 0, min_num = 1e9, sum_num = 0, size_num = 0;
        for (int &i : salary){
            max_num = max(i, max_num);
            min_num = min(i, min_num);
            sum_num += i;
            size_num++;
        }
        // double min_num = *min_element(salary.begin(),salary.end());
        // double sum_num = accumulate(salary.begin(),salary.end(),0);
        // double size_num = salary.size();
        return 1.0*(sum_num-max_num-min_num)/(size_num-2);
    }
};

int main(){
    Solution s;
    vector<int> salary = {4000,3000,1000,2000};
    cout << s.average(salary) << endl;
}
