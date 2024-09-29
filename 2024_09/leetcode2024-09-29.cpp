#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // 第一种方法如下，如果要让第k个人买完票，就说明需要让他前面的人都至多买tickets[k]张票，同时因为后面的人可能插到他的前面，又因为后面的人始终比第k个人少买一张，所以后面的人至多买tickets[k]-1张，计算即可
        // 第二种方法就是模拟
        int n = tickets.size();
        int res = 0;
        for (int i=0; i<n; i++){
            if (i <= k){
                res += min(tickets[i], tickets[k]);
            }
            else{
                res += min(tickets[i], tickets[k]-1);
            }
        }
        return res;
        // queue<pair<int, int>> q;
        // for (int i=0; i<tickets.size(); i++){
        //     q.push(make_pair(tickets[i], i));
        // }
        // int res = 0;
        // while (true){
        //     res++;
        //     auto person = q.front();
        //     q.pop();
        //     person.first--;
        //     if (person.first == 0){
        //         if (person.second == k){
        //             return res;
        //         }
        //     }
        //     else{
        //         q.push(person);
        //     }
        // }
    }
};

int main(){
    Solution s;
    vector<int> tickets = {5,1,1,1};
    int k = 0;
    cout << s.timeRequiredToBuy(tickets, k) << endl;
}
