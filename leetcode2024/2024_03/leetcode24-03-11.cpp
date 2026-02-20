#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string my_upper(string s){
        int n = s.size();
        for (int i=0; i<n; i++){
            if (s[i] >= 'A' && s[i] < 'a'){
                s[i] = 'a'+(s[i]-'A');
            }
        }
        if (n > 2){
            s[0] = 'A' + (s[0]-'a');
        }
        return s;
    }
    string capitalizeTitle(string title) {
        vector<string> str;
        string tmp_s = "";
        for (auto i : title){
            if (i == ' '){
                str.push_back(tmp_s);
                tmp_s = "";
                continue;
            }
            tmp_s += i;
        }
        str.push_back(tmp_s);
        string res;
        int n = str.size();
        for (int i=0; i<n; i++){
            res += my_upper(str[i]);
            if (i < n-1) res += " ";
        }
        return res;
    }
};

int main(int argc, char **argv){
	Solution s;
	//~ string title = "capiTalIze tHe titLe";
	//~ string title = "First leTTeR of EACH Word";
	string title = "i lOve leetcode";
	cout << s.capitalizeTitle(title) << endl;
	return 0;
}
