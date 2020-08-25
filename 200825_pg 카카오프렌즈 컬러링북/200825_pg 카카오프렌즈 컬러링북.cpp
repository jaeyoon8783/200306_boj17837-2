#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;


vector<int> solution(int m, int n, vector<vector<int>> pic)
{
	int num_area = 0;
	int max_area = 0;
	int check[100][100] = { 0 };
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check[i][j] == 0 && pic[i][j] != 0)
			{
				int su = pic[i][j];
				int t_area = 0;
				queue<pii> q;
				q.push({ i,j });
				check[i][j] = 1;
				t_area++;
				while (!q.empty())
				{
					pii t = q.front();
					q.pop();

					for (int i = 0; i < 4; i++)
					{
						int nx = t.first + dx[i];
						int ny = t.second + dy[i];

						if (nx < 0 || nx >= m || ny < 0 || ny >= n)
							continue;

						if (pic[nx][ny] == su && check[nx][ny] == 0)
						{
							t_area++;
							check[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}

				num_area++;
				if (max_area < t_area)
					max_area = t_area;

			}
		}
	}


	vector<int> ans = { num_area, max_area };
	return ans;
}


int main()
{
	int m = 6;
	int n = 4;
	vector<vector<int>> picture = { {1,1,1,0}, {1,2,2,0}, {1,0,0,1}, {0,0,0,1}, {0,0,0,3}, {0,0,0,3} };

	vector<int> a = solution(m, n, picture);
	
	cout << a[0] << ' ' << a[1];

}
