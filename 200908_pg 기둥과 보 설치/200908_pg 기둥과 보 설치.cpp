#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
	int map[102][102][2] = { 0 };

	for (int i = 0; i < build_frame.size(); i++)
	{
		int xx = build_frame[i][1];
		int yy = build_frame[i][0];
		int compo = build_frame[i][2]; // 0 기둥 1 보
		int what = build_frame[i][3]; // 설치, 삭제


		if (what == 1) // 설치
		{
			if (compo == 0) // 기
			{
				if (xx == 0 || map[xx-1][yy][0] == 1 || map[xx][yy][1] == 2 || map[xx][yy-1][1] == 2)
					map[xx][yy][0] = compo+1;
			}
			else if (compo == 1) // 보
			{
				if (map[xx-1][yy+1][0] == 1 || map[xx - 1][yy][0] == 1 || (map[xx][yy - 1][1] == 2 && map[xx][yy + 1][1] == 2))
					map[xx][yy][1] = compo + 1;
			}
		}
		else if(what == 0) // 삭제
		{
			
			map[xx][yy][compo] = 0;
			
			int can = 1;

			for (int j = 0; j <= n; j++)
			{
				for (int k = 0; k <= n; k++)
				{

					if (map[j][k][0] != 0)
					{
						if (j == 0 || map[j - 1][k][0] == 1 || map[j][k][1] == 2 || map[j][k - 1][1] == 2)
						{

						}
						else
						{
							can = 0;
							break;
						}
					}

					if (map[j][k][1] != 0)
					{
						if (map[j - 1][k+ 1][0] == 1 || map[j - 1][k][0] == 1 || (map[j][k - 1][1] == 2 && map[j][k + 1][1] == 2))
						{

						}
						else
						{
							can = 0;
							break;
						}
					}

				}
				if (can == 0)
					break;
			}
			if (can == 0)
			{
				cout << "CANT" << '\n';
				map[xx][yy][compo] = compo + 1;
			}
				
		}


		/*
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
				cout << map[i][j][0] + map[i][j][1] << ' ';
			cout << '\n';
		}
		cout << '\n';
		*/

	}


	vector<vector<int>> ans;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (map[j][i][0] != 0)
				ans.push_back({ i,j,0 });
			if (map[j][i][1] != 0)
				ans.push_back({ i,j,1 });
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << '\n';
	}



	return ans;


}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 5;

	//vector<vector<int>> build_frame = { {1, 0, 0, 1},{1, 1, 1, 1},{2, 1, 0, 1},{2, 2, 1, 1},{5, 0, 0, 1},{5, 1, 0, 1},{4, 2, 1, 1},{3, 2, 1, 1 } };
	//vector<vector<int>> build_frame = {{0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1}};
	vector<vector<int>> build_frame = { {1,0,0,1}, {1,1,1,1}, {2,1,0,1}, { 2, 1, 1, 1} };
	//vector<vector<int>> build_frame = { {1,0,0,1}, {1,1,0,1}, {1,2,1,1}, {2,1,0, 1} };
	vector<vector<int>> ans = solution(n, build_frame);

	

}
