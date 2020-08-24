#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

char map[250][250];
int x, y;
int check[250][250] = { 0 };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
pii bfs(int sx, int sy)
{
	queue<pii> q;
	int sheep = 0;
	int wolf = 0;
	q.push({ sx, sy });
	check[sx][sy] = 1;
	if (map[sx][sy] == 'o')
		sheep++;
	else if (map[sx][sy] == 'v')
		wolf++;


	while (!q.empty())
	{
		pii t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];
			if (nx >= x || nx < 0 || ny >= y || ny < 0)
				continue;

			if (check[nx][ny] == 0 && map[nx][ny] != '#')
			{
				check[nx][ny] = 1;
				q.push({ nx, ny });
				if (map[nx][ny] == 'o')
					sheep++;
				else if (map[nx][ny] == 'v')
					wolf++;
			}
		}

	}

	return { sheep, wolf };
}


int ans_s = 0;
int ans_w = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (check[i][j] == 0 && map[i][j] != '#')
			{
				pii a = bfs(i,j);

				if (a.first > a.second)
					ans_s += a.first;
				else
					ans_w += a.second;

			}
		}
	}

	cout << ans_s << ' ' << ans_w;
}
