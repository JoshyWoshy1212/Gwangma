//이동현(수정중)
#include <iostream>
#include <stack>

using namespace std;

stack<int> answer, control, control_sub;
int N, input, first[100002], storage[100002];
int countnum = 0;

int main() {
	
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> first[i];

	for (int i = N; i > 0; i++) {
		control.push(i);
	}

	for (int i = 0; i < N; i++) {

		if (first[i] > countnum) {
			for (int j = 0; j < input - countnum; j++) {
				answer.push(control.top());
				control_sub.push(control.top());
				cout << "+" << "\n";
				countnum++;
			}
			control_sub.pop();
			for (int i = 0; i < control_sub.size(); i++) {
				control.push(control_sub.top());
			}
			answer.pop();
			cout << "-" << "\n";
		}
		else if (first[i] <= countnum) {
			for (int j = 0; j < countnum - first[i]; j++) {
				answer.pop();
				control_sub.push(control.top());
				cout << "-" << "\n";
				countnum--;
			}
			answer.pop();
			cout << "-" << "\n";
		}

	}

	return 0;
}