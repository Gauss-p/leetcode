#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // �������ڣ�ȷ�����ֵ������Сֵ���������ʱ���Ա����������������������ԭ���ȼ�����
        int left = 0, right = 0; // ���ұ߽�
        // ��������ȥ�ز�������Ϊ��������ĿҪ��
        set<int> s(nums.begin(), nums.end());
        vector<int> n_nums(s.begin(), s.end());
        // ��ԭ���������������˵�͸�����
        sort(nums.begin(), nums.end());
        int n = nums.size(), m = n_nums.size();
        int res = 0;
        for (int i=0; i<m; i++){
            right = i;
            int except_left = n_nums[i]-n+1; // ��������˵�ֵ
            while (n_nums[left] < except_left){
                // ��ѭ����������˵������
                left++;
            }
            // �����µ�Ԫ��Խ�࣬��Ҫɾ����Ԫ��Խ��
            res = max(res, right-left+1);
        }
        return n-res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,2,5,3};
    cout << s.minOperations(nums) << endl;
}
