#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
	unordered_map<int, int> num;
	num[0] += 1;
	for (auto kv : num){
		cout << kv.first << kv.second << endl;
		cout << "潘潘" << endl;
	}
	cout << num[0] << endl;
	return 0;
}
