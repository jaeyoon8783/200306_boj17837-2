#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define pii pair<int, int>
using namespace std;
class pos
{
public :
	int x, y, dir;
};
int solution(vector<vector<int>> map)
{
	int x = map.size();
	int y = map[0].size();
	int check[100][100][2] = { 0 };

	queue<pos> q;
	check[0][0][0] = 1; // x,y, 0=가, 1=세;
	q.push({ 0,0,0 });

	while (!q.empty())
	{
		pos tmp = q.front();
		q.pop();
		//cout << tmp.x << ' ' << tmp.y << ' ' << tmp.dir << '\n';
		if (tmp.dir == 0) // 가로상태
		{
			pii one = { tmp.x, tmp.y };
			pii two = { tmp.x, tmp.y + 1 };
			int p_check = check[tmp.x][tmp.y][0];
			// 좌우전진
			if (two.second + 1 < y && map[two.first][two.second + 1] != 1)
			{
				if (check[tmp.x][tmp.y + 1][0] == 0)
				{
					check[tmp.x][tmp.y + 1][0] = p_check + 1;
					q.push({ tmp.x, tmp.y + 1, 0 });		
				}
				
			}
			//세로 전진
			if (one.second - 1 >= 0 && map[one.first][one.second - 1] != 1)
			{
				if (check[tmp.x][tmp.y - 1][0] == 0)
				{
					check[tmp.x][tmp.y - 1][0] = p_check + 1;
					q.push({ tmp.x, tmp.y - 1, 0 });
					
				}
				
			}
			// two를 축으로 one의 위로 회전
			if (one.first - 1 >= 0 && one.second+1 < y && map[one.first - 1][one.second] != 1 && map[one.first - 1][one.second+1] == 0)
			{
				if (check[one.first - 1][one.second + 1][1] == 0)
				{
					check[one.first - 1][one.second + 1][1] = p_check + 1;
					q.push({ one.first - 1, one.second + 1, 1 });
					//cout << one.first - 1 << ' ' << one.second + 1 << ' ' << 1 << '\n';
					
				}
			}
			//아래 범인
			if (one.first + 1 < x && one.second + 1 < y &&  map[one.first + 1][one.second] != 1 && map[one.first + 1][one.second + 1] == 0)
			{
				if (check[two.first][two.second][1] == 0)
				{
					check[two.first][two.second][1] = p_check + 1;
					q.push({ two.first, two.second, 1 });
					
					
				}
			}
			//위
			if (two.first - 1 >= 0 && two.second-1 >= 0 && map[two.first - 1][two.second] != 1 && map[two.first - 1][two.second-1] == 0)
			{
				if (check[two.first - 1][two.second - 1][1] == 0)
				{
					check[two.first - 1][two.second - 1][1] = p_check + 1;
					q.push({ two.first-1, two.second-1, 1 });
					
				}
			}
			if (two.first+ 1 < x &&two.second - 1 >= 0 && map[two.first + 1][two.second] != 1 && map[two.first + 1][two.second - 1] == 0)
			{
				if (check[one.first][one.second][1] == 0)
				{
					check[one.first][one.second][1] = p_check + 1;
					q.push({ one.first, one.second, 1 });
					
				}
			}


		}

		else if(tmp.dir == 1)
		{
			pii one = { tmp.x, tmp.y };
			pii two = { tmp.x + 1, tmp.y };
			int p_check = check[tmp.x][tmp.y][1];

			// 세로전진
			if (two.first + 1 < x && map[two.first+1][two.second] != 1)
			{
				if (check[tmp.x+1][tmp.y][1] == 0)
				{
					check[tmp.x+1][tmp.y][1] = p_check + 1;
					q.push({ tmp.x+1, tmp.y, 1 });

				//	cout << tmp.x + 1 << ' ' << tmp.y << ' ' << 1 << '\n';
				}
				
			}
			if (one.first - 1 >= 0 && map[one.first-1][one.second] != 1)
			{
				if (check[tmp.x-1][tmp.y][1] == 0)
				{
					check[tmp.x-1][tmp.y][1] = p_check + 1;
					q.push({ tmp.x-1, tmp.y, 1 });
				//	cout << tmp.x - 1 << ' ' << tmp.y << ' ' << 1 << '\n';
				}

			}
			// two를 축으로 one의 왼쪽으로 회전
			if (one.second - 1 >= 0 && one.first+1 < x && map[one.first][one.second-1] != 1 && map[one.first+1][one.second-1] == 0)
			{
				if (check[one.first + 1][one.second - 1][0] == 0)
				{
					check[one.first + 1][one.second - 1][0] = p_check + 1;
					q.push({ one.first + 1, one.second - 1, 0 });
				}
			}
			if (one.second + 1 < y &&one.first + 1 < x && map[one.first][one.second+1] != 1 && map[one.first + 1][one.second + 1] == 0)
			{
				if (check[two.first][two.second][0] == 0)
				{
					check[two.first][two.second][0] = p_check + 1;
					q.push({ two.first, two.second, 0 });
					
				}
			}
			// one을 축으로 two의 왼쪽 회전
			if (two.second - 1 >= 0 && two.first-1 >= 0 && map[two.first][two.second-1] != 1 && map[two.first - 1][two.second - 1] == 0)
			{
				if (check[two.first - 1][two.second - 1][0] == 0)
				{
					check[two.first - 1][two.second - 1][0] = p_check + 1;
					q.push({ two.first - 1, two.second - 1, 0 });
				}
			}
			if (two.second + 1 < y && two.first - 1 >= 0 && map[two.first][two.second+1] != 1 && map[two.first-1][two.second +1] == 0)
			{
				if (check[one.first][one.second][0] == 0)
				{
					check[one.first][one.second][0] = p_check + 1;
					q.push({ one.first, one.second,  0 });
				}
			}
		}



	}
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			cout << check[i][j][0] << ' ';
		cout << '\n';
	}
	cout << '\n';
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			cout << check[i][j][1] << ' ';
		cout << '\n';
	}
	
	int can1 = check[x - 1][y - 2][0];
	int can2 = check[x - 2][y - 1][1];

	if (can1 == 0)
		return can2 - 1;
	else if (can2 == 0)
		return can1 - 1;
	else
		return min(can1, can2) - 1;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	//vector<vector<int>> b = { {0,0,0,1,1}, {0,0,0,1,0}, {0,1,0,1,1}, {1,1,0,0,1}, {0,0,0,0,0} };

	vector<vector<int>> b = { {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} };

	cout << solution(b);

}
