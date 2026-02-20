#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> increase(n, 1), decrease(n, 1);
        for (int i=0; i<n-1; i++){
            if (ratings[i] < ratings[i+1]){
                increase[i+1] = increase[i]+1;
            }
        }
        for (int i=n-2; i>=0; i--){
            if (ratings[i] > ratings[i+1]){
                decrease[i] = decrease[i+1]+1;
            }
        }

        int res = 0;
        for (int i=0; i<n; i++){
            res += max(increase[i], decrease[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> ratings = {1,0,2};
    cout << s.candy(ratings) << endl;
}
