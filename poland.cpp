#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <stack>
#include <string>
using namespace std;

vector<string> middleToEnd(string expr){
    // 该函数可以将中缀表达式转换成逆波兰表达式
	unordered_map<char, int> prioritySign = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};// 定义运算符的优先级
	stack<char> ops;
	vector<string> res;
	int n = expr.size();
	string num = "";
	for (int i=0; i<n; i++){
		string tmp = "";
		char c = expr[i];
		// cout << "ts:" << c << endl;
		if (isdigit(c)){
            // 只要遇到数字就无脑加入
			num += c;
			continue;
		}
		if (num.size()){
            // 每一次如果不是数字，要检查上一次是否有存储数字
			res.push_back(num);
			num = "";
		}
		if (ops.empty() || c == '('){
            // 如果符号栈里面没有任何符号或者待加入的符号是(，那么就将符号压入符号栈中
			ops.push(c);
		}
		else{
			if (c == ')'){
                // 当遇到右括号时，我们需要将最近的一个左括号内的所有符号全部弹出
				while (!ops.empty() && ops.top() != '('){
					tmp = ops.top();
					// cout << "ts:" << tmp << endl;
					res.push_back(tmp);
					ops.pop();
				}
				ops.pop();
			}
			else{
                // 否则，按照符号的优先级，先弹出优先级高的符号，最后再压入当前符号
				while (!ops.empty() && ops.top() != '(' && prioritySign[ops.top()]>=prioritySign[c]){
					tmp = ops.top();
					res.push_back(tmp);
					ops.pop();
				}
				ops.push(c);
			}
		}
	}
    // 由于可能出现中缀表达式的最后一个字符是数字，所以这里将num再压入一次
	if (num.size()){
		res.push_back(num);
	}
    // 同时还有可能符号栈中不空，这时要将符号栈中所有符号依次弹出，并压入答案中，左括号除外
	string tmp;
	while (!ops.empty()){
		if (ops.top() != '('){
			tmp = ops.top();
			res.push_back(tmp);
		}
		ops.pop();
	}
	for (string i : res){
		cout << i << " ";
	}
	cout << endl;
	return res;
}

int calc(vector<string> vectorExpr){
    // 该函数用来计算逆波兰表达式的答案
    // 如果是数字，那么直接转换成数字压入数字栈中，否则，因为+，-，*，/都是二元运算符，所以我们在遇到这些运算符时，只需依次弹出两个数字进行运算
	stack<int> num;
	for (string s : vectorExpr){
		if (s!="+" && s!="-" && s!="*" && s!="/"){
			num.push(stoi(s));// 压入数字
		}
		else{
            // 如果是符号，那么弹出两个数字进行计算
			int b = num.top();
			num.pop();
			int a = num.top();
			num.pop();
			if (s == "+"){
				num.push(a+b);
			}
			if (s == "-"){
				num.push(a-b);
			}
			if (s == "*"){
				num.push(a*b);
			}
			if (s == "/"){
				num.push(a/b);
			}
		}
	}
    // 最终数字栈中只留下一个数字，就是答案
	return num.top();
}

int main(){
	string expr = "3*(4+5)";
	vector<string> res = middleToEnd(expr);
	cout << calc(res) << endl;
	return 0;
}
