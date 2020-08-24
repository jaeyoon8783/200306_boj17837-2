#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int mapp[5][5];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 0;
map<int, int> arr;
void go(int sx, int sy, int cnt, int cur_su)
{
	if (cnt == 6)
	{
		if (arr[cur_su] == 0)
		{
			arr[cur_su] = 1;
			ans++;
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = sx + dx[i];
		int ny = sy + dy[i];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
			continue;

		go(nx, ny, cnt + 1, cur_su * 10 + mapp[nx][ny]);
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> mapp[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			go(i, j, 1, mapp[i][j]);
		}
	}
	
	cout << ans;

}
