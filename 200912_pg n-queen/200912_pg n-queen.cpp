#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

int ga_check[12] = { 0 };
int ans = 0;
int map[12][12] = { 0 };

bool is_queen_exist(int x, int y, int n)
{
	for (int i = x - 1; i >= 0; i--)
	{
		if (map[i][y] == 1)
			return false;
	}
	for (int i = x + 1; i < n; i++)
	{
		if (map[i][y] == 1)
			return false;
	}
	for (int i = y - 1; i >= 0; i--)
	{
		if (map[x][i] == 1)
			return false;
	}
	for (int i = y + 1; i < n; i++)
	{
		if (map[x][i] == 1)
			return false;
	}

	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (map[i][j] == 1)
			return false;
	}
	for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++)
	{
		if (map[i][j] == 1)
			return false;
	}
	for (int i = x + 1, j = y - 1; i < n && j >= 0; i++, j--)
	{
		if (map[i][j] == 1)
			return false;
	}
	for (int i = x + 1, j = y + 1; i < n && j < n; i++, j++)
	{
		if (map[i][j] == 1)
			return false;
	}
	return true;

}


void go(int cur_x, int n)
{
	if (cur_x == n)
	{
		ans++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (ga_check[i] != 0)
			continue;

		bool result = is_queen_exist(cur_x, i, n);
		if (result)
		{
			map[cur_x][i] = 1;
			ga_check[i] = 1;
			go(cur_x + 1, n);
			map[cur_x][i] = 0;
			ga_check[i] = 0;
		}


	}
}



int solution(int n)
{
	go(0, n);
	return ans;
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 12;
	cout << solution(n);



}
