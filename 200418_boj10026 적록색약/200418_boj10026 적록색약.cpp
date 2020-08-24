#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

int n;
char map[100][100];
int c1[100][100] = { 0 };
int c2[100][100] = { 0 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };



void go_c1(int sx, int sy,char s)
{
	queue<pii> q;
	q.push({ sx,sy });
	c1[sx][sy] = 1;


	while (!q.empty())
	{
		pii t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (c1[nx][ny] == 0 && map[nx][ny] == s)
			{
				c1[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}

}

void go_c2(int sx, int sy, char s)
{
	queue<pii> q;
	q.push({ sx,sy });
	c1[sx][sy] = 1;


	while (!q.empty())
	{
		pii t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			
			if ((s == 'R' || s == 'G'))
			{
				if (c2[nx][ny] == 0 && (map[nx][ny] == 'R' || map[nx][ny] == 'G'))
				{
					c2[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
			else
			{
				if (c2[nx][ny] == 0 && map[nx][ny] == s)
				{
					c2[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
			
			
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (c1[i][j] == 0)
			{
				go_c1(i,j, map[i][j]);
				cnt1++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (c2[i][j] == 0)
			{
				go_c2(i, j, map[i][j]);
				cnt2++;
			}
		}
	}


	cout << cnt1 << ' ' << cnt2;
}
