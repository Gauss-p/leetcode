#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // 对于这道题目，思路是这样的，因为如果代价越大，我们需要让它被使用的次数尽可能的少，这样，我们就可以将两个代价列表进行排序，同时要记录横向和纵向总共切的数目
        // 其次循环两个列表，可以用两个指针分别循环两个列表，哪一个大就用哪一个，如果切行需要的代价更大，就先切行，然后将横向切出的块数加一，此时答案就一共需要加上切当前行的代价乘以纵向切出的快数
        // 反之，如果纵向的代价更大，就先切纵向，再将纵向切出的块数加一
        // 因为有可能在两者其中之一没有循环完的时候大循环就结束了，所以我们加两个小循环，分别切完最后的几刀即可
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        int i=0, j=0;
        int vert = 1, hori = 1;
        int res = 0;
        while (i < m-1 && j < n-1){
            if (horizontalCut[i] > verticalCut[j]){
                res += horizontalCut[i]*vert;
                hori++;
                i++;
            }
            else{
                res += verticalCut[j]*hori;
                vert++;
                j++;
            }
        }
        while (i < m-1){
            res += horizontalCut[i]*vert;
            i++;
        }
        while (j < n-1){
            res += verticalCut[j]*hori;
            j++;
        }
        return res;
    }
};

int main(){
    Solution s;
    int m = 3, n = 2;
    vector<int> horizontalCut = {1,3}, verticalCut = {5};
    cout << s.minimumCost(m, n, horizontalCut, verticalCut) << endl;
}
