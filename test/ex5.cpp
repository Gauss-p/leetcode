#include <iostream>
#include <queue>

using namespace std;

int main(){
	int a[5]={6,12,3,4,0};
	priority_queue q(a,a+5);
	q.push(100);
	while (!q.empty()){
		cout << q.top() << endl;
		q.pop();
	}
	//~ cout << q.top() << endl;
	return 0;
}
