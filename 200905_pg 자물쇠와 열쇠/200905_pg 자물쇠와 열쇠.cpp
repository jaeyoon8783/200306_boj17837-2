#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int m; // key
int n; // lock
int board_size; // 2 * m + n - 2;
vector<vector<int>> rotate(vector<vector<int>> key)
{
	vector<vector<int>> key2;

	for (int i = 0; i < key[0].size(); i++)
	{
		vector<int> tmp;
		for (int j = key.size() - 1; j >= 0; j--)
			tmp.push_back(key[j][i]);
		key2.push_back(tmp);
	}

	return key2;
}

bool gogo(int sx, int sy, vector<vector<int>> board, vector<vector<int>> key)
{
	for (int i = 0; i < key.size(); i++)
	{
		for (int j = 0; j < key.size(); j++)
		{
			board[i + sx][j + sy] = (board[i + sx][j + sy] ^ key[i][j]);
		}
	}
	int cnt = 0;
	for (int i = m - 1; i < m + n - 1; i++)
	{
		for (int j = m - 1; j < m + n - 1; j++)
		{
			cnt += board[i][j];
		}
	}
	if (cnt == n * n)
		return true;
	else
		return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{

	m = key.size();
	n = lock.size();
	board_size = 2 * m + n - 2;
	vector<vector<int>> board(board_size, vector<int>(board_size, 0));
	// lock 의 가운데는 m-1 ~ m+n-2 이다.
	for (int i = 0, ii = m - 1; ii < m + n - 1; i++, ii++)
	{
		for (int j = 0, jj = m - 1; jj < m + n - 1; j++, jj++)
		{
			board[ii][jj] = lock[i][j];
		}
	}

	/*
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
	*/

	vector<vector<int>> key2 = rotate(key);
	vector<vector<int>> key3 = rotate(key2);
	vector<vector<int>> key4 = rotate(key3);

	// lock 의 가운데는 m-1 ~ m+n-2 이다.
	// total 거리는 2 * m + n - 2;


	for (int i = 0; i <= m + n - 2; i++)
	{
		for (int j = 0; j <= m + n - 2; j++)
		{
			if (gogo(i, j, board, key))
				return true;
			if (gogo(i, j, board, key2))
				return true;
			if (gogo(i, j, board, key3))
				return true;
			if (gogo(i, j, board, key4))
				return true;
		}
	}
	return false;

}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<vector<int>> key = { {0,0,0}, {1,0,0}, {0,1,1} };
	vector<vector<int>> lock = { {1,1,1}, {1,1,0}, {1,0,1} };

	cout <<solution(key, lock);

}
