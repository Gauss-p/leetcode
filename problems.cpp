#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution2411 {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<pair<int, int>> v;// ������ѭ���в���ά��v[0]��ʹ�ã�
        // v[0].firstΪ���Ե�ǰiΪ��˵㣬���Եõ���������鰴λ��ֵ
        // v[0].secondΪ���Ե�ǰiΪ��˵㣬�ܹ��ﵽ��������鰴λ��ֵ����С�Ҷ˵�
        // ����Ϊ�˱�֤������ĳ���Ҫ�����ܵ�С
        for (int i=n-1; i>=0; i--){
            v.emplace_back(0, i);
            for (int j=0; j<(int)v.size(); j++){
                // ÿ��һ�����ݣ��ͽ�֮ǰ����Ԫ�غ������
                v[j].first |= nums[i];
            }
            // ���濪ʼά������v����ȥ�ز����������ظ��Ļ�ֵ��ֻ��Ҫ�����Ҷ˵���С����һ��
            // �����ֵ��ͬ������Ҫԭ�ؽ����治ͬ�Ļ�ֵƽ�Ƶ���ǰk+1ָ����λ��
            int k=0;
            for (int j=1; j<(int)v.size(); j++){
                if (v[j].first != v[k].first){
                    v[++k] = v[j];
                }
                else{
                    v[k].second = v[j].second;
                }
            }
            // �������¶���v�Ĵ�С����k֮��������ظ���ֵɾ��
            v.resize(k+1);
            // ͬʱ���𰸱���
            res[i] = v[0].second-i+1;
        }
        return res;
    }
};

class Solution26 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for (int i=0; i<n; i++){
            if (nums[i] != nums[j]){
                nums[j+1] = nums[i];
                j++;
            }
        }
        return j+1;
    }
};

class Solution2269 {
public:
    int divisorSubstrings(int num, int k) {
        int tmp = 0, res = 0;
        string s_num = to_string(num);
        for (int i=0; i<(int)s_num.size(); i++){
            tmp = tmp*10+(s_num[i]-'0');
            if (i < k-1) continue;
            if (tmp != 0 && num%tmp == 0){
                res++;
            }
            tmp = tmp%((int)pow(10, k-1));
        }
        return res;
    }
};

int main(){
    // Solution2411 s2411;
    // vector<int> nums = {1,0,2,1,3};
    // vector<int> res = s2411.smallestSubarrays(nums);
    // for (int i : res) cout << i << " ";
    // cout << endl;
    // -----------------------------------------------------------------
    // Solution26 s26;
    // nums = {1,1,2};
    // cout << s26.removeDuplicates(nums) << endl;
    // -----------------------------------------------------------------
    Solution2269 s2269;
    int num = 240, k = 2;
    cout << s2269.divisorSubstrings(num, k) << endl;
}
