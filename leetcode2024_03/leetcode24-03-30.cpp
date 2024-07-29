#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        // ���ȴ�С��������
        sort(coins.begin(), coins.end());
        // ����maxest_num��ʹ�ÿ���ȡ�õĽ���������ʾΪ[1, maxest_num)
        int maxest_num = 1, res = 0;
        int indx = 0, n = coins.size();
        while (maxest_num <= target){
            // ����maxest_num���޷�ȡ���ģ������ж�������Ӧ���ѵ��ڵ����Ҳ����
            if (indx < n && coins[indx] <= maxest_num){
                // �����ǰѭ������Ӳ��û��ͻ��֮ǰ������
                // ��ô���Խ���������ӳ���(maxest_num+��ǰ���)
                // ������֮ǰС��maxest_num�Ķ�ȶ�������������ôֻ��Ҫ��(maxest_num-��ǰ���)��ʼ
                // ��֮��ÿһ����ȶ����ϵ�ǰ��ȣ��Ϳ��԰������ӳ���(maxest_num+��ǰ���)
                maxest_num += coins[indx];
                indx++;
            }
            else{
                // ����Ͽ�����ô���Լ���һ��Ӳ�ң����Ķ�ȱ�֮ǰ����ȡ��������ȴ�1
                // �������Ա�֤�ܹ�����������������Ա�֤����ӵ���������
                maxest_num = maxest_num*2;
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> coins = {1,4,10,5,7,19};
    int target = 20;
    cout << s.minimumAddedCoins(coins, target) << endl;
}
