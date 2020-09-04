#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;


int solution(int x, int y, vector<string> board)
{
	char map[30][30];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			map[i][j] = board[i][j];
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';

	int ans = 0;


	while (1)
	{
		int check[30][30] = { 0 };
		for (int i = 0; i < x-1; i++)
		{
			for (int j = 0; j < y-1; j++)
			{
				if (map[i][j] == 0)
					continue;
				if (map[i][j] == map[i + 1][j] && map[i][j] == map[i][j + 1] && map[i][j] == map[i + 1][j + 1])
					check[i][j] = check[i + 1][j] = check[i][j + 1] = check[i + 1][j + 1] = 1;
			}
		}
		int tmp = 0;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (check[i][j] == 1)
				{
					tmp += check[i][j];
					map[i][j] = 0;
				}
				
			}
		}
		if (tmp == 0)
			break;
		else
			ans += tmp;


		for (int i = x - 1; i >= 0; i--)
		{
			for (int j = y - 1; j >= 0; j--)
			{
				if (map[i][j] != 0)
					continue;

				for (int k = i - 1; k >= 0; k--)
				{
					if (map[k][j] != 0)
					{
						swap(map[i][j], map[k][j]);
						break;
					}
				}
			}
		}
		/*
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
				cout << map[i][j] << ' ';
			cout << '\n';
		}
		cout << '\n';
		*/
	}

	return ans;


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x = 6;
	int y = 6;
	vector<string> board = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
	cout << solution(x, y, board);
}
