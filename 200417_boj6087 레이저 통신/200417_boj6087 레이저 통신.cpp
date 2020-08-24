#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

char map[100][100];
int check[100][100] = { 0 };
vector<pii> c;

class pos
{
public:
	int x, y, dir;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x, y;
	cin >> y >> x;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'C')
				c.push_back({ i,j });
		}
	}


	deque<pos> q;
	q.push_back({ c[0].first, c[0].second, -1 });
	check[c[0].first][c[0].second] = 1;

	while (!q.empty())
	{
		pos t = q.front();
		cout << t.x << " " << t.y << "\n";
		q.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];

			if (nx < 0 || nx >= x || ny < 0 || ny >= y || map[nx][ny] == '*')
				continue;

			if (t.dir == i)
			{
				if (check[nx][ny] == 0 || check[nx][ny] == check[t.x][t.y])//|| check[nx][ny] >= check[t.x][t.y])
				{
					check[nx][ny] = check[t.x][t.y];
					q.push_front({ nx, ny, i });
				}
			}
			else
			{
				if (check[nx][ny] == 0 || check[nx][ny] == check[t.x][t.y]+1)// || check[nx][ny] >= check[t.x][t.y] + 1)
				{
					check[nx][ny] = check[t.x][t.y] + 1;
					q.push_back({ nx,ny,i });
				}
			}

		}
		
	}


	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << check[i][j] << " ";
		}
		cout << "\n";
	}
	

	cout << check[c[1].first][c[1].second] - 2;

}


/*

7 8
.......
......C
.......
.......
.......
.......
.C.....
.......

*/













/*
10 10
C.*......C
*.*.....**
..*......*
...*.....*
.*..*....*
...*.*....
......*...
*......*..
..***..*..
....*.....

10


4 4
C.**
..**
....
...C

4 4
C...
....
**..
**.C

4 4
**.C
**..
....
C...
*/