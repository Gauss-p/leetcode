#include <iostream>
#include <vector>
using namespace std;

class BookMyShow {
// 线段树是这样的，首先，根节点存储[l,r]，这代表最大的初始区间，接下来它的左孩子和右孩子分别存储该区间的一半，我们用mid=(l+r)/2来分割区间[l,r]，所以它的左孩子就是[l, mid]，它的右孩子就是[mid+1, r]，以此类推，一直到每一个区间都被分割成l=r的大小为1的区间，我们用这些单位区间当作叶子节点。这样，一整棵二叉树的每一个节点就都用来表示一个区间了，接下来每一个节点都有一个权值，我们可以利用该二叉树是一个完全二叉树的特性，只用一个数组将所有节点的权值存储即可，同时可以发现每一个在数组中索引为i的节点，它的左孩子索引为2*i，右孩子索引为2*i+1。而查找其中元素的时候就可以用二分查找的方式，降低时间复杂度
// 线段树例子：[0,3]
//            /   \ 
//       [0,1]     [2,3]
//       /   \     /   \ 
//    [0,0][1,1] [2,2][3,3]
// 这道题目用线段树来解决，首先定义两个数组，其实它们本质上是两棵完全二叉树，但是我们可以用数组来存放，接下来分工，其中第一个数组minTree用来存储编号在区间[l,r]内的所有行中最少坐的人数，第二个数组sumTree则用来存储编号在区间[l,r]内所有行中一共坐的人数，接下来编写代码调整整棵树上所有节点对应的数字即可。
// 第一个函数modifyTree的作用是将第indx行的总共坐的人数调整至val，同时在调整的途中将minTree全部节点更新成它左右孩子的最小值，并将sumTree全部节点更新成它左右孩子的和
// 第二个函数queryMinRow用来查找编号在区间[l,r]内的所有行中，已坐人数至多为val并且编号最小的行，它可以用来查找连着坐的情况下，能坐下k个人并且编号最小的那个行
// 第三个函数querySum用来查找编号在区间[l2,r2]中所有行的已坐人数之和，它既可以用来计算单独一行的已坐人数，又可以计算多行的已坐总人数

private:
    int n;
    int m;
    vector<int> minTree; // 记录每个区间[l,r]内最少坐的人数
    vector<long long> sumTree; // 记录每个区间[l,r]内一共坐的人数

    void modifyTree(int i, int l, int r, int indx, int val){
        if (l == r){
            // 更新单位区间的权值
            minTree[i] = val;
            sumTree[i] = val;
            return;
        }
        int mid = (l+r)/2;
        // 二分查找
        if (indx <= mid){
            modifyTree(i*2, l, mid, indx, val);
        }
        else{
            modifyTree(i*2+1, mid+1, r, indx, val);
        }
        minTree[i] = min(minTree[i*2], minTree[i*2+1]); // 分别更新最小已坐人数和总共已坐人数
        sumTree[i] = sumTree[i*2]+sumTree[i*2+1];
    }

    int queryMinRow(int i, int l, int r, int val){
        if (l == r){
            if (minTree[i] > val){
                // 当前情况表示[l,r]中每一行都无法坐下val个人
                return n;
            }
            return l; // 如果能坐下，就返回可以坐下的那一行的索引
        }
        int mid = (l+r)/2;
        // 二分查找
        if (minTree[i*2] <= val){
            return queryMinRow(i*2, l, mid, val);
        }
        else{
            return queryMinRow(i*2+1, mid+1, r, val);
        }
    }

    long long querySum(int i, int l, int r, int l2, int r2){
        if (l2 <= l && r <= r2){
            // 发现一个处于要查区间内的一个之前计算过的区间，直接返回
            return sumTree[i];
        }
        int mid = (l+r)/2;
        long long sum = 0;
        // 分成两段求和，同样是二分查找
        if (mid >= l2){
            sum += querySum(i*2, l, mid, l2, r2);
        }
        if (mid+1 <= r2){
            sum += querySum(i*2+1, mid+1, r, l2, r2);
        }
        return sum;
    }

public:
    BookMyShow(int n, int m) : n(n), m(m), minTree(5*n), sumTree(5*n){
        
    }
    
    vector<int> gather(int k, int maxRow) {
        int i = queryMinRow(1, 0, n-1, m-k); // 获取能坐下k个人的最小编号的行
        if (i > maxRow){
            // 如果在maxRow以上，说明无法安排
            return {};
        }
        // 以下说明第i行一定可以安排k个人
        int curUsed = querySum(1, 0, n-1, i, i); // 计算第i行已经坐了多少人
        modifyTree(1, 0, n-1, i, curUsed+k); // 更新当前行已经坐的人数
        return {i, curUsed};
    }
    
    bool scatter(int k, int maxRow) {
        long long totalUsed = querySum(1, 0, n-1, 0, maxRow); // 计算[0,maxRow]中每一行的已坐人数总和
        if (1ll*(maxRow+1)*m-totalUsed < k){
            // 如果剩余空位不够k个，无法安排
            return false;
        }
        // 接下来更新每一行所坐的人
        int i = queryMinRow(1, 0, n-1, m-1); // 先找到第一个有空位的行，不断往后填充人
        while (true){
            long long curUsed = querySum(1, 0, n-1, i, i); // 取出当前行一共坐了多少人
            if (m-curUsed >= k){
                // 如果这k个人能全部安排到当前行，就直接更新第i行所坐的人数，跳出循环
                modifyTree(1, 0, n-1, i, curUsed+k);
                break;
            }
            // 否则，直接将当前行坐满即可
            k = k-(m-curUsed);
            modifyTree(1, 0, n-1, i, m);
            i++;
        }
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */

int main(){
    int n = 2, m = 5;
    BookMyShow* bms = new BookMyShow(n, m);
    vector<int> param1 = bms->gather(4, 0);
    for (auto i : param1) cout << i << " ";
    cout << endl;
    vector<int> param2 = bms->gather(2, 0);
    for (auto i : param2) cout << i << " ";
    cout << endl;
    bool canSit1 = bms->scatter(5, 1);
    if (canSit1) cout << "true";
    else cout << "false";
    cout << endl;
    bool canSit2 = bms->scatter(5, 1);
    if (canSit2) cout << "true";
    else cout << "fasle";
    cout << endl;
}
