#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        int left = 0, right = 0, res = 0;
        sort(ages.begin(), ages.end());
        for (auto& age : ages){
            if (age <= 14){
                // 因为如果x满足：ages[x] < ages[y]及ages[y] <= 0.5*ages[x]+7，那么x一定无法发送好友请求
                // 所以解一下方程：ages[x]<0.5*ages[x]+7即可
                continue;
            }
            while (ages[left] <= age*0.5+7){
                // 只要left满足ages[left] <= ages[x]*0.5+7，那么一定无法由x给left发送好友请求
                left++;
            }
            while (right+1 < n && ages[right+1] <= age){
                // 因为只要满足第三个条件，就一定满足第二个条件，所以我们直接用第二个条件的判断来概括第三个条件的判断即可
                // 用right+1的好处在于，每一次循环结束的时候right都指向最后一个满足限制的序号，所以计算答案的时候就可以直接用right-left+1来计算left和right之间的所有节点
                right++;
            }
            // 因为自己不能给自己发好友请求，所以减去1即可
            res += right-left;
        }
        return res;
    }
};

int main(){
	Solution s;
	vector<int> ages = {16,16};
	cout << s.numFriendRequests(ages) << endl;
}
