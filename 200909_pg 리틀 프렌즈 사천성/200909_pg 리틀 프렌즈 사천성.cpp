#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#define pii pair<int, int>
using namespace std;

class condi
{
public:
	int x;
	int y;
	int cur_dir;
	int left;
};

class first_w
{
public :
	int x; int y;
	char c;
};


void gogo(int m, int n, vector<string> board, vector<first_w> nboard, string cur, int check[], set<string> &ans)
{
	int dx[4] = { 0,0,-1,1 }; // 동서남북
	int dy[4] = { 1,-1,0,0 };


	if (cur.size() == nboard.size())
	{
		//cout << cur << '\n';
		ans.insert(cur);
		return;
	}

	for (int z = 0; z < nboard.size(); z++)
	{
		if (check[z] != 0)
			continue;

		int i = nboard[z].x;
		int j = nboard[z].y;
		char base = nboard[z].c;

		int check2[100][100] = { 0 };
		check2[i][j] = 1;
		queue<condi> q;
		for (int k = 0; k < 4; k++)
		{
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
				continue;

			if (board[nx][ny] == '.' || board[nx][ny] == base)
			{
				check2[nx][ny] = 1;
				q.push({ nx, ny, k, 1 });
			}
		}

		while (!q.empty())
		{
			condi t = q.front();
			q.pop();
			if (board[t.x][t.y] == base)
			{
				check[z] = 1;
				board[t.x][t.y] = board[i][j] = '.';
				gogo(m, n, board, nboard, cur + base, check, ans);
				check[z] = 0;
				board[t.x][t.y] = board[i][j] = base;
				break;
			}

			for (int k = 0; k < 4; k++)
			{
				int nx = t.x + dx[k];
				int ny = t.y + dy[k];
				if (nx < 0 || nx >= m || ny < 0 || ny >= n)
					continue;

				if (k == t.cur_dir) // 방향이 같으면
				{
					if (board[nx][ny] == '.' || board[nx][ny] == base)
					{
						if (check2[nx][ny] == 0)
						{
							check2[nx][ny] = 1;
							q.push({ nx, ny, k, t.left });
						}

					}

				}
				else if (k != t.cur_dir && t.left > 0) // 다르지만 한번까진 꺾기 가능
				{
					if (board[nx][ny] == '.' || board[nx][ny] == base)
					{
						if (check2[nx][ny] == 0)
						{
							check2[nx][ny] = 1;
							q.push({ nx, ny, k, t.left - 1 });
						}
					}
				}

			}
		}

	}

}



string solution(int m, int n, vector<string> board)
{
	
	map<char, int> mm;
	vector<first_w> nboard;

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] >= 'A' && board[i][j] <= 'Z' && mm[board[i][j]] == 0)
			{
				mm[board[i][j]] = 1;
				nboard.push_back({ i,j, board[i][j] });
			}
		}
	}
	
	int check[100];
	for (int i = 0; i < nboard.size(); i++)
	{
		check[i] = 0;
	}

	set<string> ans;
	gogo(m, n, board, nboard, "", check, ans);


	if (ans.size() == 0)
		return "IMPOSSIBLE";
	else
	{
		auto itr = ans.begin();
		return (*itr);
	}
	

}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	//int m = 4;
	//int n = 4;
	//vector<string> board = { ".ZI.", "M.**", "MZU.", ".IU." };
	int m = 3;
	int n = 3;
	vector<string> board = { "DBA", "C*A", "CDB" };
	cout << solution(m, n, board);

}
