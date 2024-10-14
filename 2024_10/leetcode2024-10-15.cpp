#include <iostream>
using namespace std;

class Solution {
public:
    int maxH(int r, int b){
        int h = 0;
        while (true){
            // 高度即对应每一行的球的个数
            if (r > 0){
                h++;
                r -= h;
                if (r < 0){
                    h--;
                    break;
                }
            }
            else{
                break;
            }
            if (b > 0){
                h++;
                b -= h;
                if (b < 0){
                    h--;
                    break;
                }
            }
            else{
                break;
            }
        }
        return h;
    }
    int maxHeightOfTriangle(int red, int blue) {
        int res = maxH(red, blue); // 先排红球
        res = max(res, maxH(blue, red)); // 先排蓝球
        return res;
    }
};

int main(){
    Solution s;
    int r = 2, b = 4;
    cout << s.maxH(r, b) << endl;
}
