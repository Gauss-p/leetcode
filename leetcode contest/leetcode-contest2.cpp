#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> c(26);
        for (auto &i : word){
            c[i-'a']++;
        }
        sort(c.begin(), c.end());
        // ǰ�ò������洢��С��������Ҫ��ȥ����
        int res = 1e6, front_sub = 0;
        for (auto &i : c){
            if (i == 0) continue;
            // int min_num = i;
            // ����������������i����ô���Ҫ��֤���ݲ�������С�ڻ����k����Ҫ��֤��������Ϊi+k
            int max_limit = i+k;
            // ���ò������洢����ϴ�������Ҫ��ȥ����
            int back_sub = 0;
            for (auto &j : c){
                if (j > max_limit){
                    back_sub += j-max_limit;
                }
            }
            // ÿ��������Ժ󣬾ͼ���һ����С�Ĵ�
            res = min(res, front_sub+back_sub);
            // ����Ժ���һ����һ�����Ϊ��Сֵ����ʱǰ�ò�͵ü��ϵ�ǰ�����
            front_sub += i;
        }
        return res;
    }
};

int main(){
    string word = "dabdcbdcdcd";
    int k = 2;
    Solution s;
    cout << s.minimumDeletions(word, k) << endl;
    return 0;
}
