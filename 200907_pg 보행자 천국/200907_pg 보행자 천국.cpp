#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pii pair<int, int>
#define NA 20170805
#define MOD 20170805
using namespace std;
int d[500][500][4] = { 0 }; //[i][j][0] == 서->동   [i][j][2] = 북->남



int solution(int m, int n, vector<vector<int>> cm) // 내 코드 (틀림)
{

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			d[i][j][0] = d[i][j][1] = 0;
	}


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
