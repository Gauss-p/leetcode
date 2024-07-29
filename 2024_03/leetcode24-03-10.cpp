#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<string, int> dic;
        dic["A"] = 0;
        dic["B"] = 0;
        int n = secret.size();
        for (int i=0; i<n; i++){
            if (guess[i] == secret[i]){
                guess[i] = '*';
                secret[i] = '*';
                dic["A"]++;
            }
        }
        for (int i=0; i<n; i++){
            if (guess[i] == '*') continue;
            auto it = secret.find(guess[i]);
            if (it != string::npos){
                secret[it] = '*';
                dic["B"]++;
            }
        }
        string res = to_string(dic["A"])+"A"+to_string(dic["B"])+"B";
        return res;
    }
};

int main(int argc, char **argv){
	Solution s;
	string secret = "1807", guess = "7810";
	cout << s.getHint(secret, guess) << endl;
	return 0;
}
