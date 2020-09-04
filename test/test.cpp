#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int answer = 0x7f7f7f7f;

void dfs(int n, int number, int idx, int sum, string strr) {
	if (idx > 8) return;

	if (sum == number) {
		if (answer > idx)
		{
			cout << strr << '\n';
			answer = idx;
		}
		
	}

	int tmp = 0;
	for (int i = 0; i < 8; i++) {
		tmp = tmp * 10 + n;
		dfs(n, number, idx + i + 1, sum + tmp, strr+'+');
		dfs(n, number, idx + i + 1, sum - tmp, strr + '-');
		dfs(n, number, idx + i + 1, sum*tmp, strr + '*');
		dfs(n, number, idx + i + 1, sum / tmp, strr + '/');
	}
}

int solution(int N, int number) {
	dfs(N, number, 0,0, "");
	if (answer > 8) return -1;
	else return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	/*
	int n = 8;
	int num;
	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		 answer = 0x7f7f7f7f;
		cout << solution(n, num) << '!';
	}
	*/
	int n = 8;
	int num = 8890;
	cout << solution(n, num) << '!';
}
/*
void dfs(int n, int number, int idx, int sum, string str) {
	if (idx > 8) return;

	if (sum == number) {
		answer = min(answer, idx);
	}

	int tmp = 0;
	for (int i = 0; i < 8; i++) {
		tmp = tmp * 10 + n;
		dfs(n, number, idx + i + 1, sum + tmp, str+"+");
		dfs(n, number, idx + i + 1, sum - tmp, str + "-");
		dfs(n, number, idx + i + 1, sum*tmp, str + "*");
		dfs(n, number, idx + i + 1, sum / tmp, str + "/");
	}
}

*/