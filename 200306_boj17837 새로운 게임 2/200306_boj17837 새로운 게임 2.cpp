#include <iostream>
#include <vector>
using namespace std;

int map[13][13];
int dx[5] = { 0, 0, 0, -1, 1 }; 
int dy[5] = { 0, 1,-1, 0 , 0 };

int horse_pos[13][13][5] = { 0 }; // n층엔 몇번 말이 있을까?? 
int horse_max_pos[13][13] = { 0 }; // 몇층까지 있나? 
class Horse 
{ public : int x, y, dir; // dir >> 1,2,3,4 == 동서북남 
	int cur_pos; };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j]; // 흰 / 빨 / 파
		}
	}
	Horse horse[11];

	for (int i = 1; i <= k; i++)  // 1 ~ k horse
	{
		cin >> horse[i].x >> horse[i].y >> horse[i].dir;

		horse_pos[horse[i].x][horse[i].y][1] = i;
		horse_max_pos[horse[i].x][horse[i].y] = 1;
		horse[i].cur_pos = 1;
	}

	int turn;
	for (turn = 1; turn <= 1000; turn++)
	{

		for (int i = 1; i <= k; i++)
		{

			int prev_x = horse[i].x;
			int prev_y = horse[i].y;
			int nx = horse[i].x + dx[horse[i].dir];
			int ny = horse[i].y + dy[horse[i].dir];


			if (nx <= 0 || nx > n || ny <= 0 || ny > n || map[nx][ny] == 2)
			{
				if (horse[i].dir == 1)
					horse[i].dir = 2;
				else if (horse[i].dir == 2)
					horse[i].dir = 1;
				else if (horse[i].dir == 3)
					horse[i].dir = 4;
				else if (horse[i].dir == 4)
					horse[i].dir = 3;

				nx = prev_x + dx[horse[i].dir];
				ny = prev_y + dy[horse[i].dir];

				if(nx <= 0 || nx > n || ny <= 0 || ny > n || map[nx][ny] == 2)
					continue;
			}


			if (map[nx][ny] == 0)
			{
				//horse[i].x = nx;
				//horse[i].y = ny;

				int prev_max_pos = horse_max_pos[horse[i].x][horse[i].y] - horse[i].cur_pos + 1; //  전은 몇층 ~ 몇층   1~3층이면 3개
				int next_max_pos = horse_max_pos[nx][ny];     //여기에 쌓을꺼임

				if (prev_max_pos + next_max_pos >= 4)
				{
					cout << turn;
					return 0;
				}
				else
				{
					int cnt = 0;
					int start = horse[i].cur_pos;
					int end = horse_max_pos[prev_x][prev_y];
					for (int j = start; j <= end; j++)
					{
						int who = horse_pos[prev_x][prev_y][j];  // 무슨말이냐?

						horse[who].x = nx;
						horse[who].y = ny;
						horse[who].cur_pos = next_max_pos + (++cnt);

						horse_max_pos[prev_x][prev_y]--;
						horse_max_pos[nx][ny]++;
						horse_pos[nx][ny][horse[who].cur_pos] = who;

					}
				}
			}
			else if (map[nx][ny] == 1)
			{
				int prev_max_pos = horse_max_pos[horse[i].x][horse[i].y] - horse[i].cur_pos + 1; //  전은 몇층 ~ 몇층   1~3층이면 3개
				int next_max_pos = horse_max_pos[nx][ny];     //여기에 쌓을꺼임

				if (prev_max_pos + next_max_pos >= 4)
				{
					cout << turn;
					return 0;
				}
				else
				{
					int cnt = 0;
					int start = horse[i].cur_pos;
					int end = horse_max_pos[prev_x][prev_y];
					for (int j = end; j >= start; j--)
					{
						int who = horse_pos[prev_x][prev_y][j];  // 무슨말이냐?

						horse[who].x = nx;
						horse[who].y = ny;
						horse[who].cur_pos = next_max_pos + (++cnt);

						horse_max_pos[prev_x][prev_y]--;
						horse_max_pos[nx][ny]++;
						horse_pos[nx][ny][horse[who].cur_pos] = who;

					}
				}
			}
			else if (nx <= 0 || nx > n || ny <= 0 || ny > n || map[nx][ny] == 2) //  nx = 1~n
			{
			}

			/*
			for (int j = 1; j <= k; j++)
			{
				cout << j << " " << horse[j].x << " " << horse[j].y << " " << horse[j].dir << " " << horse[j].cur_pos << "\n";
			}
			cout << "\n";
			*/
		}

	}
	cout << -1;
}