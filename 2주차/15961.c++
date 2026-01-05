//15961 투 포인터
#include <iostream>
#include <set>

using namespace std;

int N, d, k, c, arr[15001], ans = 0, true_ans = 0;
set<int> mySet;

int main() {
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		int sushi = i % 8;
		for (int j = 0; j < k; j++)
			mySet.insert(arr[i + j]);

		set<int>::iterator it = mySet.find(c);
		if (it != mySet.end())ans = mySet.size();
		else ans = mySet.size() + 1;

		mySet.clear();
		if (ans > true_ans) true_ans = ans;
	}

	cout << true_ans;
	return 0;
}