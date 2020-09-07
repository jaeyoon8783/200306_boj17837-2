#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
#define NA 20170805
#define MOD 20170805
using namespace std;


int solution(int m, int n, vector<vector<int>> cm) // 내 코드 (틀림)
{
	int d[500][500][4] = { 0 }; //[i][j][0] == 서->동   [i][j][2] = 북->남
	if (m == 1 && n == 1)
		return 1;

	for (int i = 1; i < m; i++)
	{
		if (cm[i][0] == 1)
			break;
		d[i][0][2] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		if (cm[0][i] == 1)
			break;
		d[0][i][0] = 1;
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (cm[i][j] == 1)
				continue;
			if (cm[i - 1][j] == 0)
				d[i][j][2] = (d[i][j][2] + d[i - 1][j][0] + d[i - 1][j][2]) % NA;
			else if (cm[i - 1][j] == 2)
				d[i][j][2] = (d[i][j][2] + d[i - 1][j][2]) % NA;

			if (cm[i][j - 1] == 0)
				d[i][j][0] = (d[i][j][0] + d[i][j - 1][0] + d[i][j - 1][2]) % NA;
			else if (cm[i][j - 1] == 2)
				d[i][j][0] = (d[i][j][0] + d[i][j - 1][0]) % NA;
			
		}
		
	}
	/*
	for (int i = 0; i <m ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << d[i][j][0] << '/' << d[i][j][2] << ' ';
		}
		cout << '\n';
	}
	*/

	int ans = (d[m - 1][n - 1][0] + d[m - 1][n-1][2]) % NA;
	return ans;

}

int solution2(int m, int n, vector<vector<int>> city_map) // 정답코드
{ //

	int answer = 0;

	int fromLeft[501][501] = { 0 };
	int fromTop[501][501] = { 0 };

	fromTop[1][1] = fromLeft[1][1] = 1;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {


			if (city_map[i - 1][j - 1] == 0) {
				fromLeft[i][j] += (fromLeft[i][j - 1] + fromTop[i - 1][j]) % MOD;
				fromTop[i][j] += (fromLeft[i][j - 1] + fromTop[i - 1][j]) % MOD;
			}
			else if (city_map[i - 1][j - 1] == 1) {
				fromLeft[i][j] = 0;
				fromTop[i][j] = 0;
			}
			else {
				fromLeft[i][j] = fromLeft[i][j - 1];
				fromTop[i][j] = fromTop[i - 1][j];
			}
		}
	}
	/*
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << fromLeft[i][j] << '/' << fromTop[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	answer = (fromLeft[m][n - 1] + fromTop[m - 1][n]) % MOD;
	return answer;
}


void go(vector<vector<int>> cm, int x, int y)
{
	if (x == cm.size() - 1 && y == cm.size() - 2)
	{
		if (solution(cm.size(), cm[0].size(), cm) != solution2(cm.size(), cm[0].size(), cm))
		{
			for (int i = 0; i < cm.size(); i++)
			{
				for (int j = 0; j < cm[0].size(); j++)
				{
					cout << cm[i][j] << ' ';
				}
				cout << '\n';
			}
			cout << '\n';

		}
		
		return;
	}

	if (y == cm[0].size())
	{
		x++; y = 0;
	}

	for (int i = 0; i < 3; i++)
	{
		cm[x][y] = i;
		go(cm, x, y + 1);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	

	//vector<vector<int>> cm = { {0,0,0,1,0,0}, {0,0,2,0,1,0}, {1,0,0,2,2,0}, {0,2,0,0,0,2}, {0,2,0,1,0,2}, {0,2,0,1,0,2} };
	//vector<vector<int>> cm = { {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0} };
	//vector<vector<int>> cm = { {0,2,0,1,0,0}, {0,0,2,0,1,2}, {1,0,0,2,2,0}, {0,2,0,2,0,2}, {0,0,0,1,0,2}, {0,2,0,1,0,2} };
	//vector<vector<int>> cm = { {0,2,0,1,0,0}, {0,0,2,0,1,2}, {1,0,0,2,2,0}, {0,2,0,2,0,2}, {0,0,0,1,0,2}, {0,2,0,1,0,2}, {0,2,0,1,0,0}, {0,0,2,0,1,2}, {1,0,0,2,2,0}, {0,2,0,2,0,2}, {0,0,0,1,0,2}, {0,2,0,1,0,2} };
	//vector<vector<int>> cm = { {0,2,2,2,2,2,2,0} };
	//vector<vector<int>> cm = { {0,2,0,1,0,0}, {0,0,2,0,1,2}, {1,0,0,2,2,0}, {0,2,0,2,0,2}, {0,0,0,1,0,2}, {0,2,0,1,0,2}, {0,2,0,1,0,0}, {0,0,2,0,1,2}, {1,0,0,2,2,0}, {0,2,0,2,0,2}, {0,0,0,1,0,2}, {0,2,0,1,0,2} };
	//vector<vector<int>> cm = { {0} };


	vector<vector<int>> cm(6, vector<int>(6, 0));


	go(cm, 0, 1);




	//cout << solution(cm.size(), cm[0].size(), cm) << ' ';
	//cout << solution2(cm.size(), cm[0].size(), cm);

}
