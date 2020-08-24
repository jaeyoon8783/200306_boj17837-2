#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;


int dx[] = { -1, 1, 0,0 };
int dy[] = { 0,0,-1, 1 };

int check[1000][1000][11] = { 0 };
int map[1000][1000];
class pos
{
public :
	int x, y, k;
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x, y, k;
	char str;
	cin >> x >> y >> k;
	

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> str;
			map[i][j] = str - '0';
		}
	}

	queue<pos> q;
	q.push({ 0,0,0 });
	check[0][0][0] = 1;

	while (!q.empty())
	{
		pos t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];

			if (nx < 0 || nx >= x || ny < 0 || ny >= y)
				continue;

			if (map[nx][ny] == 0 && check[nx][ny][t.k] == 0)
			{
				check[nx][ny][t.k] = check[t.x][t.y][t.k] + 1;
				q.push({ nx, ny, t.k });
			}
			else if (map[nx][ny] == 1 && t.k + 1 <= k && check[nx][ny][t.k + 1] == 0)
			{
				check[nx][ny][t.k + 1] = check[t.x][t.y][t.k] + 1;
				q.push({ nx, ny, t.k + 1 });
			}
		}

	}
	int ans = 987654321;
	for (int i = 0; i <= k; i++)
	{
		if(check[x-1][y-1][i] != 0)
			ans = min(ans, check[x - 1][y - 1][i]);
	}
	if (ans == 987654321)
		cout << -1;
	else
		cout << ans;


}
