#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int sm = 0;
        for (auto& c : s){
            if (c == '['){
                sm++;
            }
            else if (sm > 0){
                sm--;
            }
        }
        return (sm+1)/2;
    }
};

int main(){
    Solution sl;
    string s = "][][";
    cout << sl.minSwaps(s) << endl;
}
