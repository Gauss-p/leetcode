#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence), sout;
        // ����stringstream�Ĺ��ܣ�ֱ�Ӱ��ո��з־���
        // ��Ϊ��󷵻صĴ���ÿһ�����ֶ�Ҫ������λС�������Կ�����c++�е�setprecision��ȡ��λС��
        // �����˼·�Ƕ���ÿһ�������ĵ���,�����ж�,�����һ���ַ���'$'���߳���Ϊ1,����
        // ����,���еڶ���,�����ȥ��һ��'$'��ʣ�µĶ�������,�ͽ��м���
        // ���ڸ���Ƚϴ������,���ǿ���ֱ����stoll���ַ���ת��Ϊlong long���ͽ��м���
        // ����֮��ֱ�Ӽ������մ𰸼���
        sout << fixed << setprecision(2);
        string tmp;
        while (getline(ss, tmp, ' ')){
            if (tmp[0] != '$' || tmp.size() == 1){
                sout << tmp;
            }
            else{
                int tmp_size = tmp.size();
                int cnt = 0;
                for (int i=1; i<tmp_size; i++){
                    if (tmp[i] >= '0' && tmp[i] <= '9'){
                        cnt++;
                    }
                }
                if (cnt == tmp_size-1){
                    double val = stoll(tmp.substr(1, tmp.size()-1))*(100.00-discount)/100.00;
                    sout << "$" << val;
                }
                else{
                    sout << tmp;
                }
            }
            sout << " ";
        }
        string res = sout.str();
        res.pop_back();
        return res;
    }
};

int main(){
    Solution s;
    string sentence = "there are $1 $2 and 5$ candies in the shop";
    int discount = 50;
    cout << s.discountPrices(sentence, discount) << endl;
}
