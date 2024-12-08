#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int n;
    int minMoves(vector<int> lst, unordered_map<int, int> cnt){
        int x0 = (cnt[1]>cnt[0] ? 1 : 0); // 判断开头元素
        // 下面一行中，(i%2)^x0即为正确交替数组中第i位的元素，和x异或就可以求出是否相同
        int diff = 0;
        for (int i=0; i<n; i++){
            int x = lst[i];
            diff += ((i%2)^x0)^x;
        }
        return n%2==1 ? diff/2 : min(diff, n-diff)/2; // 注意偶数有两种情况
    }
public:
    int movesToChessboard(vector<vector<int>>& board) {
        // 经过分析，我们可以发现，交换两列时，每一行的元素含量是不变的，交换两行时，每一列的元素含量是不变的，所以，如果在交换两行之前两列相同，交换后它们依然相同，如果在交换两列之前两行相同，交换后它们也依然相同，那么从结果倒推，可以发现，如果最后要变换成“棋盘”，那么在最开始的board数组中一定必须只存在两种行，一种是A，一种是B，其中A是由数组[0,1,0,1,.....]变换而来，B是由数组[1,0,1,0,.....]变换而来
        // 也就是说，board中所有行必须恰好只有两种，并且每一种行的1含量和0含量之差最大为1。当n为偶数的时候，每一行中1的含量和0的含量之差为0，当n为奇数的时候，每一行中1的含量和0的含量之差为1。为了计算方便，我们将第一行作为基准行，首先判断第一行的0含量和1含量相差是否小于等于1，之后我们直接判断board的剩余行中，是否只存在以下两种行：1.和第一行相同 2.每个位置上的数都不等于第一行中相同位置的数 即可。而在进行上述判断的过程中，我们即可保证board中也有且仅有两种列
        // 在判断第一行是否合法的同时，我们也需要判断第一列是否合法。在python中，我们用zip(*board)的方式来获得矩阵board的反制，接下来获取其中第一行就相当于board中的第一列
        // 最后我们还需要获取总共的移动次数，我们发现，因为每一行、每一列的数值只有0和1，并且在整个board矩阵中只有两种行和两种列，所以我们只需要将第一行和第一列都按顺序排列，计算总共的移动次数即可
        // 对于第一行和第一列，我们可以将正确的交替数组[0,1,0,1,....]列出来，然后分别与第一行和第一列比较，计算出不相同的位置数量，除以二即可得到需要交换的次数
        // 在计算过程中，我们需要注意以下三种情况：
        // 1.第一行中0的含量大于1的含量，那么正确的交替数组开头为0 
        // 2.第一行中1的含量大于0的含量，那么正确的交替数组开头为1 
        // 3.第一行中0的含量等于1的含量，那么正确的交替数组开头可以是1，也可以是0，我们可以默认置为0，然后在返回答案的时候将两种情况取最小值即可。
        // 我们发现，如果一个长度为n的数组和交替数组[0,1,0,1,....]的不同位置数量为diff的话，它和交替数组[1,0,1,0,....]的不同位置数量就为n-diff，所以对于上面的第三种情况，返回min(diff,n-diff)//2即可
        // 对于第一列,也是相同的操作,最后分别求出第一行和第一列需要交换的次数,相加即可

        // 判断第一行是否合法
        vector<int> firstRow = board[0];
        unordered_map<int, int> rowCnt; // 统计第一行中0和1的含量
        for (int&i : firstRow) rowCnt[i]++;
        if (abs(rowCnt[0]-rowCnt[1]) > 1){
            return -1;
        }

        // 判断第一列是否合法
        vector<int> firstCol; // 取出第一列
        for (auto&i : board){
            firstCol.push_back(i[0]);
        }
        unordered_map<int, int> colCnt;
        for (int&i : firstCol){
            colCnt[i]++;
        }
        if (abs(colCnt[0]-colCnt[1]) > 1){
            return -1;
        }

        // 判断矩阵中是否只有两种行
        n = board.size();
        for (int i=0; i<n; i++){
            bool flag = (board[i][0] == board[0][0]); // 当开头不同时,当前行中所有元素都应该与第一行中对应元素不同
            for (int j=1; j<n; j++){
                // 判断所有元素
                if ((board[i][j] == board[0][j]) != flag){
                    return -1;
                }
            }
        }
        
        // 计算第一行和第一列的最小移动次数，相加即可
        return minMoves(firstRow, rowCnt)+minMoves(firstCol, colCnt);
    }
};

int main(){
    Solution s;
    vector<vector<int>> board = {{0,1,1,0},{0,1,1,0},{1,0,0,1},{1,0,0,1}};
    cout << s.movesToChessboard(board) << endl;
}
