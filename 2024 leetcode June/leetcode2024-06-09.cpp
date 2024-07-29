#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> val(n+2, 1);
        // ������Ŀ�й涨������ԭ���������������Ҷ�Ԫ�صĴ�����Ҫ�������ڵ��Ǹ�����Ϊ1
        // ���Զ���һ��������val���洢���ǣ���nums���������߸���һ��1
        for (int i=0; i<n; i++){
            val[i+1] = nums[i];
        }
        vector<vector<int>> memo(n+2, vector<int>(n+2, -1));
        // ��ά����memo������ɼ��仯����
        function<int(int, int)> solve = [&](int l, int r){
            // �ú����������㿪����(l, r)������ܹ���ȡ��Ӳ����
            // ���ģ�⣬��Ҫɾ�������ѡ������򷴣����ǿ��Լ�������
            // ÿһ�μ����������(l, r)�У���Ϊ������ģ�⣬�����൱������ֻʣ������l+1, r-1�Լ������������
            // ��������������������򣬽���õ�Ӳ������val[l]*val[m]*val[r]
            // ������������ǳƴ����������������m
            // ��Ҫ��֤��Ӳ������󣬻���Ҫ����(l, m)�����Ӳ�����Լ�(m, r)�����Ӳ�����������
            // ��˾ͳ����˵ݹ飬ͬʱΪ�˼�����ʱ�����仯������Ҫ�����ó�
            // ����������ֱ�ӷ��ؼ���õ�ֵ����
            if (l >= r-1) return 0;
            int& res = memo[l][r];
            if (res != -1) return res;
            res = 0;
            for (int m=l+1; m<r; m++){
                int tmp_sum = val[l]*val[m]*val[r];
                tmp_sum += solve(l, m)+solve(m, r);
                res = max(res, tmp_sum);
            }
            return res;
        };
        return solve(0, n+1);
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,1,5,8};
    cout << s.maxCoins(nums) << endl;
}
