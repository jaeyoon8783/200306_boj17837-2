//2105
#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;

int x, y,t;
int map[200][200];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void set_bomb()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (map[i][j] == 2)
				map[i][j] = 1;
			else
				map[i][j] = 3;

		}
	}
}

void bomb()
{
	int check[200][200] = { 0 }; // 폭탄이었던것

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			map[i][j] -= 1;
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (map[i][j] == 0 && check[i][j] == 0)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= x || ny < 0 || ny >= y)
						continue;

					if (map[nx][ny] == 2)
					{
						map[nx][ny] = 0;
						check[nx][ny] = 1;
					}
				}
			}


		}
	}

	
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y >> t;
	char str;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> str;
			if (str == '.')
				map[i][j] = 0;
			else
				map[i][j] = 2;
		}
	}


	for (int z = 2; z <= t; z++)
	{
		if (z % 2 == 0)
			set_bomb();
		else
			bomb();

	}

	
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (map[i][j] == 0)
				cout << '.';
			else
				cout << 'O';
		}
		cout << '\n';
	}
		
}
