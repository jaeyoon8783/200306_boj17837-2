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
public:
	int x; int y;
	char c;
};

bool comp(const first_w& a, const first_w& b)
{
	return a.c < b.c;
}


vector<first_w> nboard;
string ans;
int dx[4] = { 0,0,-1,1 }; // 동서남북
int dy[4] = { 1,-1,0,0 };
char board2[100][100];

bool gogo(int m, int n, int i, int j)
{
	
	char base = board2[i][j];

	int check[100][100] = { 0 };
	check[i][j] = 1;
	queue<condi> q;

	for (int k = 0; k < 4; k++)
	{
		int nx = i;
		int ny = j;
		while (1)
		{
			nx += dx[k];
			ny += dy[k];


			if (board2[nx][ny] == '.' || board2[nx][ny] == base)
			{
				if (board2[nx][ny] == base)
				{
					board2[nx][ny] = board2[i][j] = '.';
					return true;
				}
				check[nx][ny] = 1;
				q.push({ nx, ny, k, 1 });
				
			}
			else
				break;

		}

	}
		
		
	while (!q.empty())
	{
		condi t = q.front();
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = t.x;
			int ny = t.y;
			while (1)
			{
				nx += dx[k];
				ny += dy[k];
				if (nx < 0 || nx >= m || ny < 0 || ny >= n)
					break;


				if (k == t.cur_dir) // 방향이 같으면
				{
					if (board2[nx][ny] != '.' && board2[nx][ny] != base)
						break;

					if (check[nx][ny] == 0)
					{
						if (board2[nx][ny] == base)
						{
							board2[nx][ny] = board2[i][j] = '.';
							return true;
						}
						check[nx][ny] = 1;
						q.push({ nx, ny, k, t.left });
						
					}
				}
				else if (k != t.cur_dir && t.left == 1) // 다르지만 한번까진 꺾기 가능
				{
					if (board2[nx][ny] != '.' && board2[nx][ny] != base)
						break;

					if (check[nx][ny] == 0)
					{
						if (board2[nx][ny] == base)
						{
							board2[nx][ny] = board2[i][j] = '.';
							return true;
						}
						check[nx][ny] = 1;
						//q.push({ nx, ny, k, 0 });
					}

				}

			}
		}
	}

	return false;

}


string solution(int m, int n, vector<string> board)
{
	map<char, int> mm;

	nboard.clear();
	ans = "";


	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			board2[i][j] = board[i][j];
			if (board[i][j] >= 'A' && board[i][j] <= 'Z' && mm[board[i][j]] == 0)
			{
				mm[board[i][j]] = 1;
				nboard.push_back({ i,j, board[i][j] });
			}
		}
	}

	sort(nboard.begin(), nboard.end(), comp);
	bool flag = true;
	while (flag)
	{
		flag = false;
		for(int i = 0 ; i < nboard.size() ; i++)
		{
			flag = gogo(m, n, nboard[i].x, nboard[i].y);

			if (flag == true)
			{
				ans += nboard[i].c;
				cout << ans << '\n';
				nboard.erase(nboard.begin() + i);
				break;
			}

		}

	}
	if (nboard.size() != 0)
		return "IMPOSSIBLE";
	else
		return ans;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	//int m = 4;
	//int n = 4;
	//vector<string> board = { "NRYN", "ARYA" };

	vector<string> board = { "FGHEI", "BAB..", "D.C*.", "CA..I", "DFHGE" };
	//vector<string> board = { "FG...", ".....", "...*.", ".....", ".F.G." };
	//vector<string> board = { "...", "D.C", "C.." };
	cout << solution(board.size(), board[0].size(), board);

} 