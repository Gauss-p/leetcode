#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        for (int l=1; l<=n; l++){
            for (int i=0; i<n-l+1; i++){
                int cur_or = 0;
                for (int j=i; j<i+l; j++){
                    cur_or = cur_or | nums[j];
                    // cout << cur_or << " " << nums[j] << endl;
                }
                if (cur_or >= k){
                    return l;
                }
            }
        }
        return -1;
    }
};

class Solution2 {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int> rear(n);
        int score = 0;
        for (int i=n-1; i>0; i--){
            if (possible[i] == 0){
                score--;
            }
            else{
                score++;
            }
            rear[i] = score;
        }
        score = 0;
        for (int i=0; i<n-1; i++){
            if (possible[i] == 0){
                score--;
            }
            else{
                score++;
            }
            if (score > rear[i+1]){
                return i+1;
            }
        }
        return -1;
    }
};

class Solution3 {
public:
    int minimumSubarrayLength2(vector<int>& nums, int k) {
        // ��һ�����伫Ϊ���Ƶ���Ŀ��2411.��λ��������С�����鳤��
        int n = nums.size();
        vector<pair<int, int>> v;
        // ������ѭ���в���ά��v[0]��ʹ�ã�
        // v[0].firstΪ���Ե�ǰiΪ��˵㣬���Եõ���������鰴λ��ֵ
        // v[0].secondΪ���Ե�ǰiΪ��˵㣬�ܹ��ﵽ��������鰴λ��ֵ����С�Ҷ˵�
        // ����Ϊ�˱�֤������ĳ���Ҫ�����ܵ�С
        int res = INT_MAX;
        for (int i=n-1; i>=0; i--){
            v.emplace_back(0, i);
            // ÿ�ν�ѭ��������v�����һ��Ԫ��
            int m = v.size();
            for (int j=0; j<m; j++){
                // ÿ��һ�����ݣ��ͽ�֮ǰ����Ԫ�غ������
                // ͬʱ�����жϣ����������k����ô�ͽ��𰸺ʹ�ʱ�ĳ�������Сֵ
                v[j].first |= nums[i];
                if (v[j].first >= k){
                    // ����С
                    res = min(res, v[j].second-i+1);
                }
            }
            // ���濪ʼά������v����ȥ�ز����������ظ��Ļ�ֵ��ֻ��Ҫ�����Ҷ˵���С����һ��
            // �����ֵ��ͬ������Ҫԭ�ؽ����治ͬ�Ļ�ֵƽ�Ƶ���ǰk+1ָ����λ��
            int k=0;
            for (int l=1; l<m; l++){
                if (v[l].first != v[k].first){
                    // ����ͬ��ֵ�����
                    v[++k] = v[l];
                }
                else{
                    // ������ͬ��ֵ�����
                    v[k].second = v[l].second;
                }
            }
            v.resize(k+1);
            // �������¶���v�Ĵ�С����k֮��������ظ���ֵɾ��
        }
        return res==INT_MAX ? -1 : res;
    }
};

int main(){
    Solution1 s1;
    vector<int> nums = {1,2,3};
    int k = 2;
    cout << s1.minimumSubarrayLength(nums, k) << endl;
    // -----------------------------------------------------------------
    Solution2 s2;
    vector<int> possible = {1,0,1,0};
    cout << s2.minimumLevels(possible) << endl;
    // -----------------------------------------------------------------
    Solution3 s3;
    vector<int> nums2 = {2,1,8};
    int k2 = 10;
    cout << s3.minimumSubarrayLength2(nums2, k2) << endl;
}
