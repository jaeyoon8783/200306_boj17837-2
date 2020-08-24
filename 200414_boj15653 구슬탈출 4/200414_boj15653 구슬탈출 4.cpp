#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int x, y;
char map[10][10];
int rx, ry, bx, by, gx, gy;
int check[10][10][10][10] = { 0 };
int ans = 999999999;

class Pos
{
public : 
	int rx, ry, bx, by, cnt, prev; // prev = dir cnt = 구른 횟수
};

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

			if (map[i][j] == 'R')
			{
				rx = i; ry = j; map[i][j] = '.';

			}
			else if (map[i][j] == 'B')
			{
				bx = i;	by = j;	map[i][j] = '.';
			}
			else if (map[i][j] == 'O')
			{
				gx = i;	gy = j;	map[i][j] = '.';
			}
		}
	}

	queue<Pos> q;
	q.push({ rx,ry,bx,by,1,-1 });
	check[rx][ry][bx][by] = 1;

	while (!q.empty())
	{
		Pos p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			if (p.prev == i)
				continue;
			
			int nrx = p.rx; int nry = p.ry; int nbx = p.bx; int nby = p.by;
			while (1)
			{
				int move_r = 0, move_b = 0;
				while (nrx != -1)
				{
					nrx += dx[i];
					nry += dy[i];

					if (nrx == gx && nry == gy)
					{
						nrx = -1;
						nry = -1;
						move_r = 1;
						break;
					}


					if (map[nrx][nry] != '.' || ((nrx == nbx) && (nry == nby)))
					{
						nrx -= dx[i];
						nry -= dy[i];
						break;
					}
					move_r = 1;

				}

				while (nbx != -1)
				{
					nbx += dx[i];
					nby += dy[i];

					if (nbx == gx && nby == gy)
					{
						nbx = -1;
						nby = -1;
						move_b = 1;
						break;
					}

					if (map[nbx][nby] != '.' || ((nrx == nbx) && (nry == nby)))
					{
						nbx -= dx[i];
						nby -= dy[i];
						break;
					}
					move_b = 1;
				}
				if (move_b == 0 && move_r == 0)
					break;


			}

			//cout << nrx << " " << nry << " " << nbx << " " << nby << ' ' << i << "\n";

			if (nrx == -1)
			{
				if (nbx != -1)
				{
					//if (check[gx][gy][nbx][nby] == 0)
					//	check[gx][gy][nbx][nby] = p.cnt + 1;
					ans = min(ans, p.cnt + 1);
				}
			}
			else if (nrx != -1 && nbx != -1)
			{
				if (check[nrx][nry][nbx][nby] == 0)
				{
					check[nrx][nry][nbx][nby] = p.cnt + 1;
					q.push({ nrx, nry, nbx, nby, p.cnt+1, i });
				}
			}

		}
	}

	/*
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (check[gx][gy][i][j] != 0)
				ans = min(ans, check[gx][gy][i][j]);
		}
	}
	*/
	if (ans == 999999999)
		cout << -1;
	else
		cout << ans-1;
}
/*
10 10
##########
#R#...#O.#
#...#.#..#
#####.#..#
#B#.#.#..#
#####.#..#
#.....#..#
#.#####..#
#........#
##########

*/