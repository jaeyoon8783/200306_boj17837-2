#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

int x, y;
int map[20][20];
queue<pii> q;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans = 0;
void go(int cnt, int cur)
{
	if (cnt == 2)
	{
		int can = 0;
		int check[20][20] = { 0 };

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (check[i][j] == 0 && map[i][j] == 2)
				{
					int cnt = 0;
					check[i][j] = 1;
					q.push({ i,j });


					while (!q.empty())
					{
						pii t = q.front();
						q.pop();

						if (map[t.first][t.second] == 2)
							cnt++;
						else
							cnt = -99999;


						for (int i = 0; i < 4; i++)
						{
							int nx = t.first + dx[i];
							int ny = t.second + dy[i];
							if (nx < 0 || nx >= x || ny < 0 || ny >= y || check[nx][ny] == 1)
								continue;

							if (map[nx][ny] == 0 || map[nx][ny] == 2)
							{
								check[nx][ny] = 1;
								q.push({ nx,ny });
							}
						}

					}
					cout << cnt << "\n";
					if (cnt > 0)
						can += cnt;

				}
			}
		}
		ans = max(ans, can);



		return;
	}

	while (cur < x*y)
	{
		int tx = cur / y;
		int ty = cur % y;

		if (map[tx][ty] == 0)
		{
			map[tx][ty] = 1;
			go(cnt + 1, cur + 1);
			map[tx][ty] = 0;
		}
		cur++;
	}



}




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

	go(0,0);
	cout << ans;
}
