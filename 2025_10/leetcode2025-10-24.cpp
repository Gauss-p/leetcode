#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool is_balanced(int x){
        vector<int> cnt(10, 0);
        while (x){
            if (cnt[x%10] >= x%10){
                return false;
            }
            cnt[x%10]++;
            x /= 10;
        }
        for (int i=0; i<10; i++){
            if (cnt[i] > 0 && cnt[i] != i){
                return false;
            }
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        int res = n+1;
        while (!is_balanced(res)){
            res++;
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 1;
    cout << s.nextBeautifulNumber(n) << endl;
}
