#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(), cards.end());
        int n = cards.size();
        int sum = 0;
        int odd = 0, even = 0;
        for (int i=n-1; i>=n-cnt; i--){
            sum += cards[i];
            if (cards[i] & 1){
                odd = cards[i];
            }
            else{
                even = cards[i];
            }
        }
        if (sum % 2 == 0){
            return sum;
        }
        for (int i=n-cnt-1; i>=0; i--){
            if (cards[i] & 1){
                if (even != 0){
                    return sum-even+cards[i];
                }
            }
            else{
                if (odd != 0){
                    return sum-odd+cards[i];
                }
            }
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<int> cards = {1,2,3,4};
    int cnt = 2;
    cout << s.maximumScore(cards, cnt) << endl;
}
