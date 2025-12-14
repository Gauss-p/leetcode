#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        int modNum = 1e9+7;
        int last = -1;
        int res = 1;
        int tot = 0;
        for (int i=0; i<corridor.size(); i++){
            char c = corridor[i];
            if (c == 'S'){
                tot += 1;
                if ((tot&1) && tot>1){
                    res = 1ll*res*(i-last)%modNum;
                }
                last = i;
            }
        }
        return (tot%2==0 && tot>=2) ? res : 0;
    }
};

int main(){
    Solution s;
    string corridor = "SSPPSPS";
    cout << s.numberOfWays(corridor) << endl;
}
