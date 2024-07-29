#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

unordered_map<int, vector<string>> son_str(string s){
	unordered_map<int, vector<string>> dic;
	int n = s.size();
	//~ dic[n] = {s};
	for (int i=1; i<=n; i++){
		for (int j=0; j<n-i+1; j++){
			dic[i].push_back(s.substr(j, i));
		}
		sort(dic[i].begin(), dic[i].end());
	}
	return dic;
}

bool is_find(string str, vector<string> arr, string fa_str){
	int cnt = 0;
	for (auto &s : arr){
		//~ if (s == fa_str) continue;
		if (s.find(str) != string::npos){
			cnt++;
			//~ return false;
		}
	}
	if (cnt >= 2) return false;
	return true;
}	

int main(){
	//~ string s = "abc";
	vector<string> arr = {"abc","bcd","abcd"};
	//~ vector<string> arr = {"cab","ad","bad","c"};
	//~ vector<string> arr = {"fhi","ct","s","o","o"};
	vector<string> res;
	for (auto &s : arr){
		bool flag = false;
		//~ cout << "s = " << s << endl;
		unordered_map<int, vector<string>> dic = son_str(s);
		int n = s.size();
		int length = 0;
		while (length <= n){
			length++;
			for (auto &ch : dic[length]){
				//~ cout << "---->" << ch << endl;
				if (is_find(ch, arr, s)){
					res.push_back(ch);
					cout << ch << endl;
					flag = true;
					break;
				}
			}
			if (flag){
				break;
			}
		}
		if (!flag){
			res.push_back("");
			cout << "------" << endl;
		}
	}
	//~ for (auto &kv : dic){
		//~ cout << kv.first << ":";
		//~ for (auto v : kv.second){
			//~ cout << v << " ";
		//~ }
		//~ cout << endl;
	//~ }
	return 0;
}
