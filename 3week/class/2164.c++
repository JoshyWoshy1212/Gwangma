//이동현
#include <iostream>
#include <queue>

using namespace std;

int N, tikto=0;
queue<int> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		ans.push(i+1);

	while(true) {
		if (ans.size() == 1) {
			cout << ans.front();
			return 0;
		}

		if (tikto==0) {
			ans.pop();
			tikto++;
		}
		else {
			ans.push(ans.front());
			ans.pop();
			tikto--;;
		}
	}

	return 0;
}