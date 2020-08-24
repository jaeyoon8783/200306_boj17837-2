#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define pii pair<int, int>
using namespace std;

//서 1 북 2 동 4 남 8
int x,y;
int map[50][50];
int check[50][50] = { 0 };
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
int su[2501] = { 0 };
int cnt_max = 0;
void BFS(int sx, int sy, int cnt)
{
	queue<pii> q;
	check[sx][sy] = cnt;
	q.push({ sx,sy });
	su[cnt]++;
	while (!q.empty())
	{
		pii t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			if ((map[t.first][t.second] & (1 << i)) == 0)
			{
				int nx = t.first + dx[i];
				int ny = t.second + dy[i];
				if (check[nx][ny] == 0)
				{
					check[nx][ny] = cnt;
					q.push({ nx, ny });
					su[cnt]++;
				}
				
			}
		}
	}

	cnt_max = max(cnt_max, su[cnt]);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> y >> x;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> map[i][j];
		}
	}

	int cnt = 1;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (check[i][j] == 0)
				BFS(i, j, cnt++);
		}
	}

	/*
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << check[i][j] << ' ';
		}
		cout << "\n";
	}
	*/
	set<pii> s;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= x || ny < 0 || ny >= y)
					continue;
				if (check[i][j] > check[nx][ny])
					s.insert({ check[nx][ny], check[i][j] });
				else if (check[i][j] < check[nx][ny])
					s.insert({check[i][j], check[nx][ny] });
			}
		}
	}


	int maxx = 0;
	set<pii>::iterator itr = s.begin();

	for (itr; itr != s.end(); itr++)
	{
		maxx = max(maxx, (su[itr->first] + su[itr->second]));
		//cout << itr->first << ' ' << itr->second << '\n';
	}
	

	cout << cnt-1 << "\n" << cnt_max << "\n" << maxx;

}
