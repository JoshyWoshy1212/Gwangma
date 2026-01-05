//12841 누적 합

#include <iostream>
using namespace std;

int N, crosswalknum;
int crosswalk[100002] = { 0 };
long long leftpath[100002] = { 0 };
long long rightpath[100002] = { 0 };
long long temp, ans = 1e18;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> crosswalk[i];
	}

	for (int i = 1; i < N; i++) {
		cin >> leftpath[i];
		leftpath[i] += leftpath[i - 1];
	}

	for (int i = 1; i < N; i++) {
		cin >> rightpath[i];
		rightpath[i] += rightpath[i - 1];
	}

	for (int i = 0; i < N; i++) {
		temp = crosswalk[i] + leftpath[i] + rightpath[N - 1] - rightpath[i];
		if (temp < ans) {
			ans = temp;
			crosswalknum = i + 1;
		}
	}

	cout << crosswalknum << " " << ans;

	return 0;
}