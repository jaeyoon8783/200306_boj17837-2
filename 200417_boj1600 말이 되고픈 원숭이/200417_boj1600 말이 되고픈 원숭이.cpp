#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;
//1940
int map[200][200];
int check[200][200][31] = { 0 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int h_dx[] = { 1,1,2,2,-1,-1,-2,-2 };
int h_dy[] = { -2,2,-1,1,-2,2,-1,1 };
class pos
{
public :
	int x, y, k;
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int k, x, y;
	cin >> k >> y >> x;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> map[i][j];
		}
	}

	queue<pos> q;
	q.push({ 0,0,k });
	check[0][0][k] = 1;

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

			if (check[nx][ny][t.k] == 0 && map[nx][ny] == 0)
			{
				check[nx][ny][t.k] = check[t.x][t.y][t.k] + 1;
				q.push({ nx,ny,t.k });
			}
		}

		if (t.k > 0)
		{
			for (int i = 0; i < 8; i++)
			{
				int nx = t.x + h_dx[i];
				int ny = t.y + h_dy[i];

				if (nx < 0 || nx >= x || ny < 0 || ny >= y)
					continue;

				if (check[nx][ny][t.k-1] == 0 && map[nx][ny] == 0)
				{
					check[nx][ny][t.k-1] = check[t.x][t.y][t.k] + 1;
					q.push({ nx,ny,t.k-1 });
				}
			}
		}

	}
	int ans = 987654321;
	for (int i = 0; i <= k; i++)
	{
		if (check[x - 1][y - 1][i] != 0)
			ans = min(ans, check[x - 1][y - 1][i]);
	}
	if (ans == 987654321)
		cout << -1;
	else
		cout << ans-1;
}


/*


1
4 4
0 1 0 0
1 1 0 0
0 0 1 1
0 1 0 0



*/