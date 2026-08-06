#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true){
            int cur = 1;
            for (auto& c : to_string(n)) cur *= (c-'0');
            if (cur%t == 0){
                return n;
            }
            n++;
        }
        return -1;
    }
};

int main(){
    Solution s;
    int n = 15, t = 3;
    cout << s.smallestNumber(n, t) << endl;
}
