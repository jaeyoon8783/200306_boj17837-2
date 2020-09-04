#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int ans = 987654321;

void go(int cur_su, int cur_cnt, int n, int num)
{
	if (cur_cnt >= 9)
		return;

	if (cur_su == num)
	{
		ans = min(ans, cur_cnt);
		return;
	}


	int tmp_su = n;
	int tmp_cnt = cur_cnt + 1;
	while (tmp_cnt <= 8)
	{
		go(cur_su + tmp_su, tmp_cnt, n, num);
		go(cur_su - tmp_su, tmp_cnt, n, num);
		go(cur_su * tmp_su, tmp_cnt, n, num);
		go(cur_su / tmp_su, tmp_cnt, n, num);

		tmp_su = tmp_su * 10 + n;
		tmp_cnt++;
	}




}

int solution(int n, int num)
{
	go(0, 0, n, num);

	if (ans == 987654321)
		return -1;
	else
		return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);




	int n = 8;
	int num = 11095;
	cout << solution(n, num) << '?';

}

