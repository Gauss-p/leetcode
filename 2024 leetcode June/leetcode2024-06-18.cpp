#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence), sout;
        // 利用stringstream的功能，直接按空格切分句子
        // 因为最后返回的答案中每一个数字都要保留两位小数，所以可以用c++中的setprecision来取两位小数
        // 大体的思路是对于每一个独立的单词,首先判断,如果第一个字符是'$'或者长度为1,跳过
        // 否则,进行第二步,如果除去第一个'$'后剩下的都是数字,就进行计算
        // 对于个别比较大的数字,我们可以直接用stoll将字符串转化为long long类型进行计算
        // 计算之后直接加入最终答案即可
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
