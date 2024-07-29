#include <iostream>
#include <vector>
#include <functional>
#include <string>
using namespace std;

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        // �ܵ�˼·�������������������ÿһ��������Ϊ��һ��Ԫ�����������Ȼ�����еĿ����ۼӵ�һ�𼴿�
        // ��Ϊ��������Ե�һ��Ԫ�ؽ���һ��ѭ��̫���ӣ�����ֱ�ӽ�������dfs��
        // ÿһ��ѭ��Ϊ���ʵ�Ԫ�أ����������򣬾�ֱ�ӽ�����һ��ѭ����ֱ��������Ԫ�ض�����һ��
        // �����������׳�ʱ�����Խ����Ż�
        // ��һ��������λ��������Ż���ÿһ��Ԫ��������ʹ����ͽ����Ԫ�ص�����indxȡ��
        // ȡ���󱣴��һ����������(1<<indx)��Ҳ���Ǵ����ҵ�iλ�Ƿ�Ϊ1�ʹ������Ƿ���ʹ�
        // ÿһ�δ���ʱ�����޸ļ���
        // �ڶ��ַ�����ֱ���ô�õĶ�����������ַ������ٽ���ǰ���һ�����ֱ���ַ����������á�-������
        // ƴ�Ӻõ��ַ�����Ϊ��������õĴ���Ϊֵ�������ֵ�memo�м���
        // ÿ���ж��Ƿ��������Ϳ��Խ�ʡʱ��
        int n = nums.size();
        int mod_num = 1e9+7;
        vector<vector<int>> memo(1<<n, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int prevPos, int u){
            if (u == (1<<n)-1){
                return 1;
            }
            if (prevPos != -1 && memo[u][prevPos] != -1){
                return memo[u][prevPos];
            }
            int res = 0;
            for (int i=0; i<n; i++){
                if (((u >> i) & 1) == 0){
                    if (prevPos == -1 || nums[i]%nums[prevPos] == 0 || nums[prevPos]%nums[i] == 0){
                        res = (res+dfs(i, u|(1<<i)))%mod_num;
                    }
                }
            }
            if (prevPos != -1){
                memo[u][prevPos] = res%mod_num;
            }
            return res%mod_num;
        };
        return dfs(-1, 0);
        // ���´������ͨ��
        // int n = nums.size();
        // int mod_num = 1e9+7;
        // unordered_map<string, int> memo;
        // vector<int> visited(n, 0);
        // function<int(int, int, int)> dfs = [&](int depth, int prevPos, int u){
        //     if (depth == n){
        //         return 1;
        //     }
        //     string key = to_string(prevPos)+"-"+to_string(u);
        //     if (memo.count(key)){
        //         return memo[key];
        //     }
        //     int &res = memo[key];
        //     for (int i=0; i<n; i++){
        //         if (visited[i] == 0){
        //             if (prevPos == -1 || nums[i]%nums[prevPos]==0 || nums[prevPos]%nums[i] == 0){
        //                 visited[i] = 1;
        //                 res = (res+dfs(depth+1, i, u|(1<<i)))%mod_num;
        //                 visited[i] = 0;
        //             }
        //         }
        //     }
        //     return res;
        // };
        // return dfs(0, -1, 0)%mod_num;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2, 3, 6};
    cout << s.specialPerm(nums) << endl;
}
