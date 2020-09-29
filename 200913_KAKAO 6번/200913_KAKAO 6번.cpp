#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define pii pair<int, int>
using namespace std;


vector<pii> card_pos[7];
vector<int> conti;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

class point
{
public :
	int x, y, c;
};
class comp
{
public:
	bool operator() (const point& a, const point& b) const
	{
		return a.c > b.c;
	}
};



int go(vector<vector<int>> board, int sx, int sy, int cur_conti, int conti_pos, int ccnt)
{
	int tmp_cnt = ccnt;
	int e1x = card_pos[cur_conti][0].first;
	int e1y = card_pos[cur_conti][0].second;
	int e2x = card_pos[cur_conti][1].first;
	int e2y = card_pos[cur_conti][1].second;
	//sx -> e1 -> e2

	int check[4][4] = { 0 };
	check[sx][sy] = 1;

	priority_queue<point, vector<point>, comp> q;
	q.push({ sx,sy, 1});

	while (!q.empty())
	{
		point t = q.top();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];

			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
				continue;

			if (check[nx][ny] == 0)
			{
				check[nx][ny] = t.c + 1;
				q.push({ nx, ny, check[nx][ny] });
			}
			while (1)
			{
				nx = t.x + dx[i];
				ny = t.y + dy[i];
			}

		}
		
	}






	// sx -> e2 -> e1
	





}



int solution(vector<vector<int>> board, int r, int c)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			if (board[i][j] == 0)
				continue;
			card_pos[board[i][j]].push_back({ i, j });
		}
	}

	for (int i = 1; i <= 6; i++)
	{
		if (card_pos[i].size() != 0)
			conti.push_back(i);
	}

	int ans = 9999999;
	while (1)
	{

		int cnt = go(board, r, c, 0, 0, 0);
		ans = min(ans, cnt);

		if (!next_permutation(conti.begin(), conti.end()))
			break;
	}

	


}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);



	vector<vector<int>> board = { {1,0,0,3}, {2,0,0,0}, {0,0,0,2}, {3,0,1,0} };
	int r = 1;
	int c = 0;
	cout << solution(board, r, c);

}
