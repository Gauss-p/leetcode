#include <iostream>
#include <climits>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        // ˼·�������ģ����ǿ��Է������������һ���ǿ���ֱ���øı�����ֵ�ٽ��������մ��Ŀ��
        // �ڶ����Ǿ��㽫���еĸı���������涼û�취���Ŀ��
        // ���ȿ��ǵ�һ��,��ΪҪ������λ�ú��Լ�����λ�õĽ�����,���������վ����������1���м�
        // ���û������������1,��������,�������1��,������c���洢nums���������1����Ŀ
        // ���Է��֣��������������1�����ǿ��Ի��������õ�����������������ͻ���һ���õ����������򲻻�������1��
        // ��ȡ����վ�ص���Χ�Ľ�Һ����ǿ���ͨ�����Ա�����һ��1���ٰ��µ�1��������ǰλ�ò�ʰȡ�ķ����õ�maxChanges����ң���Ϊ�ǵ�һ�������Ҳ�����������иı�Ļ�������ȡ��k����ң������Ƴ�����һ������Ĳ������ǣ�max(0, c-1)+(k-c)*2������������Ҫ��֤maxChanges >= k-c
        // �������ڶ�����������ʱ���������maxChanges��Ҳû�취�ﵽk�����
        // �������Ǿ���Ҫ���������ط��Ľ����,����֪��,����Ҫ�ҵ�k-maxChanges����Ҳ��ܴ��Ŀ��
        // Ϊ�˷���˵��,���ǳ�moveSize = k-maxChanges
        // ���ȱ�������1��λ��,����������Ҫ��һ��λ��,ʹ�����λ�õ���ΧmoveSize��1�ľ���֮����С,����֪��,���λ�þ���k��1��λ�õ���λ��
        // ����,����ֻ��Ҫ�ڴ洢1��λ�õ�����pos�б�������,ÿһ�ζ���k��1��λ��,��ȡ���е���λ�����м��㼴��
        // Ϊ�˷�����㣬���ǿ����Ƶ�һ����֪һ�����ݵ���λ�����������λ������������Ԫ�ؾ���֮��
        // ��Ϊ����ط���˵��������ʵ�Ѿ����մ�С�����˳�������������ǳ�С������λ������Ϊ��λ����ߵ�������������λ������Ϊ��λ���ұߵ���
        // ����Ҫ��ģ�����λ�����������Ĳ�ľ���ֵ�ĺͣ����Զ�����ߵ��������ǿ�������ߵ����ĸ���������λ���ټ�ȥ������ߵ����ĺͣ������ұߵ��������ǿ������ұߵ����ĸ���������λ���ټ�ȥ�����ұߵ����ĺ�
        // Ҳ���Ƿֶ���ͣ������Ӽ���
        // ���������ߵ�����֮�ͣ�������ǰ׺��������
        // ע��,��������ֻ���������Ҫͨ��һ��һ���ƶ���1������Ҫ���ٲ�,����������ǻ���Ҫ����maxChanges����maxChanges��1,����ҪmaxChanges*2��
        // ����,�����һ����Ҫ:��moveSize��1�ƶ���һ��λ�õ���С����,����maxChanges*2����
        vector<int> pos;
        int c = 0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            if (nums[i] == 0) continue;
            pos.push_back(i);
            c = max(c, 1);
            if (i > 0 && nums[i-1] == 1){
                if (i > 1 && nums[i-2] == 1){
                    c = 3;
                }
                else{
                    c = max(c, 2);
                }
            }
        }
        c = min(c, k);
        if (maxChanges >= k-c){
            return max(0, c-1)+2*(k-c);
        }

        int len_pos = pos.size();
        int moveSize = k-maxChanges;
        long long res = LLONG_MAX;
        vector<long long> prev_sum(n+1, 0);
        for (int i=0; i<len_pos; i++){
            prev_sum[i+1] = prev_sum[i]+pos[i];
        }

        for (int r=moveSize; r<len_pos+1; r++){
            int l = r-moveSize;
            int mid = l+moveSize/2;
            long long s1 = 1ll*pos[mid]*(mid-l)-1ll*(prev_sum[mid]-prev_sum[l]);
            long long s2 = 1ll*(prev_sum[r]-prev_sum[mid])-1ll*pos[mid]*(r-mid);
            res = min(res, s1+s2);
            // cout << s1 << " " << s2 << endl;
        }
        return res+2*maxChanges;
    }
};

int main(){
    bitset<16> bs(1);
    cout << bs.to_string() << endl;
    string cur = bs.to_string();
    cur = cur.substr(cur.size()-1, 1);
    cout << cur << endl;
    // Solution s;
    // vector<int> nums = {1,1,0,0,0,1,1,0,0,1};
    // int k = 3, maxChanges = 1;
    // cout << s.minimumMoves(nums, k, maxChanges) << endl;
}
