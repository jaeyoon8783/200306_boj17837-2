#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;
int x, y;

char map[1500][1500];
int check[1500][1500] = { 0 };
int check_duck[1500][1500] = { 0 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<pii> bird;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y;

	queue<pii> q;
	int cur = 1;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'L')
			{
				bird.push_back({ i,j });
				map[i][j] = '.';
			}
			if (map[i][j] == '.')
			{
				q.push({ i,j });
				check[i][j] = 1;
			}
		}
	}
	




	queue<pii> cur_duck;
	

	cur_duck.push({ bird[0].first, bird[0].second });
	check_duck[bird[0].first][bird[0].second] = 1;


	int day = 0;
	while (1)
	{
		queue<pii> next_duck;
		
		while (!cur_duck.empty())
		{
			pii t = cur_duck.front();
			cur_duck.pop();


			for (int i = 0; i < 4; i++)
			{
				int nx = t.first + dx[i];
				int ny = t.second + dy[i];

				if (nx < 0 || nx >= x || ny < 0 || ny >= y)
					continue;

				if (check_duck[nx][ny] == 0)
				{
					if (map[nx][ny] == '.')
					{
						check_duck[nx][ny] = 1;
						cur_duck.push({ nx, ny });
					}
					else if (map[nx][ny] == 'X')
					{
						check_duck[nx][ny] = 1;
						next_duck.push({ nx, ny });
					}
					
				}
				
			}
		}
		
		if (check_duck[bird[1].first][bird[1].second] == 1)
			break;
	

		cur_duck = next_duck;


		while (!q.empty())
		{
			pii t = q.front();

			if (check[t.first][t.second] == day + 2) // day 0에선 check가 1까지만 탐색해야 한다.
				break;
			q.pop();


			for (int i = 0; i < 4; i++)
			{
				int nx = t.first + dx[i];
				int ny = t.second + dy[i];

				if (nx < 0 || nx >= x || ny < 0 || ny >= y)
					continue;

				if (check[nx][ny] == 0 && map[nx][ny] == 'X')
				{
					check[nx][ny] = check[t.first][t.second] + 1;
					map[nx][ny] = '.';
					q.push({ nx,ny });

				}
			}


		}

		day++;
	}

	cout << day;
}


/*

8 17
...XXXXXX..XX.XXX
....XXXXXXXXX.XXX
...XXXXXXXXXXXX..
..XXXXX..XXXXXX.L
.XXXXXX..XXXXXX..
XXXXXXX...XXXX...
..XXXXX...XXX....
....XXXXX.XXXL...


20 20
LXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXL

*/