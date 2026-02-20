#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for (auto& s : operations){
            if (s[1] == '+'){
                res++;
            }
            else{
                res--;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> operations = {"--X","X++","X++"};
    cout << s.finalValueAfterOperations(operations) << endl;
}
